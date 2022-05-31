#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int n, m;

int ice[301][301];

int distx[4] = { -1, 0, 1, 0 };
int disty[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ice[i][j];
		}
	}

	int t = 0;
	bool check = false;

	while (1) {
		bool visit[301][301] = { false, };

		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (visit[i][j]) continue;
				if (ice[i][j] == 0) continue;

				cnt++;

				queue<pair<int, int> > q;
				q.push({i, j});
				while (!q.empty()) {
					int nodex = q.front().second;
					int nodey = q.front().first;
					q.pop();

					if (visit[nodey][nodex]) continue;

					visit[nodey][nodex] = true;

					for (int k = 0; k <= 3; k++) {
						int nextx = nodex + distx[k];
						int nexty = nodey + disty[k];

						if (nextx < 1 || nextx > m || nexty < 1 || nexty > n) continue;

						if (visit[nexty][nextx]) continue;

						if (ice[nexty][nextx] == 0) continue;

						q.push({nexty, nextx});
					}
				}
			}
		}

		if (cnt == 0) {
			check = false;
			break;
		}

		if (cnt > 1) {
			check = true;
			break;
		}

		int minus[301][301] = { 0, };

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (ice[i][j] == 0) continue;
				int count = 0;
				for (int k = 0; k <= 3; k++) {
					int nextx = j + distx[k];
					int nexty = i + disty[k];
					if (nextx < 1 || nextx > m || nexty < 1 || nexty > n) continue;
					if (ice[nexty][nextx] == 0) count++;
				}

				minus[i][j] = count;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (ice[i][j] - minus[i][j] < 0) ice[i][j] = 0;
				else ice[i][j] -= minus[i][j];
			}
		}

		t++;
	}

	if (check) cout << t;
	else cout << 0;

	return 0;
}
