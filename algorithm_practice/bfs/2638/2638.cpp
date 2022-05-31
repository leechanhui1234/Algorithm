#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

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
	while (1) {
		bool check = true;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (cheeze[i][j] == 1) check = false;
			}
		}

		if (check) break;

		queue<pair<int, int> > q;

		q.push({ 1, 1 });

		bool visit[101][101] = { false, };

		while (!q.empty()) {
			int nodex = q.front().second;
			int nodey = q.front().first;
			q.pop();

			if (visit[nodey][nodex]) continue;

			visit[nodey][nodex] = true;

			for (int i = 0; i <= 3; i++) {
				int nextx = nodex + distx[i];
				int nexty = nodey + disty[i];

				if (nextx < 0 || nextx > m || nexty < 0 || nexty > n) continue;

				if (cheeze[nexty][nextx] == 1) continue;

				q.push({nexty, nextx});
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (cheeze[i][j] == 0) continue;

				int cnt = 0;

				for (int k = 0; k <= 3; k++) {
					int nextx = j + distx[k];
					int nexty = i + disty[k];

					if (nextx < 0 || nextx > m || nexty < 0 || nexty > n) continue;

					if (!visit[nexty][nextx]) continue;

					cnt++;
				}

				if (cnt >= 2) cheeze[i][j] = 0;
			}
		}

		t++;
	}

	cout << t;

	return 0;
}
