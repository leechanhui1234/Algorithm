#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int n, m;

int cheeze[101][101];

int distx[4] = { -1, 0, 1, 0 };
int disty[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> cheeze[i][j];
		}
	}

	int t = 0;
	int ans = 0;
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (cheeze[i][j] == 1) answer++;
		}
	}

	while (1) {
		bool check = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (cheeze[i][j] == 1) {
					check = false;
				}
			}
		}

		if (check) break;

		ans = 0;

		bool visit[101][101] = {false, }; //치즈 녹아 없어질 부분 파악

		queue<pair<int, int> > q;

		q.push({1, 1});

		while (!q.empty()) {
			int nodex = q.front().second;
			int nodey = q.front().first;

			q.pop();

			if (visit[nodey][nodex]) continue;

			visit[nodey][nodex] = true;

			for (int i = 0; i <= 3; i++) {
				int nextx = nodex + distx[i];
				int nexty = nodey + disty[i];

				if (nextx <= 0 || nextx > m || nexty <= 0 || nexty > n) continue;

				if (visit[nexty][nextx]) continue;

				if (cheeze[nexty][nextx] == 1) continue;

				q.push({nexty, nextx});
			}
		}

		bool c = true;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (cheeze[i][j] == 0) continue;

				c = false;

				for (int k = 0; k <= 3; k++) {
					int checkx = j + distx[k];
					int checky = i + disty[k];

					if (checkx <= 0 || checkx > m || checky <= 0 || checky > n) continue;

					if (visit[checky][checkx]) cheeze[i][j] = 0;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (cheeze[i][j] == 0) continue;
				ans++;
			}
		}

		if (ans != 0) answer = ans;

		t++;
	}

	cout << t << '\n' << answer;

	return 0;
}
