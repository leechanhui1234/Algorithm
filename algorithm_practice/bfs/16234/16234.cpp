#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int country[51][51];
int l, r;
int n;

struct Point {
	int x;
	int y;
	int node;
};

int distx[4] = { -1, 0, 1, 0 };
int disty[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> country[i][j];
		}
	}

	int day = 0;

	while (1) {
		int visit[51][51] = { 0, };
		int ind = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (visit[i][j] != 0) continue;

				Point pt;
				pt.x = j;
				pt.y = i;
				pt.node = country[i][j];

				queue<Point> q;

				q.push(pt);

				while (!q.empty()) {
					int nodex = q.front().x;
					int nodey = q.front().y;
					int ga = q.front().node;

					q.pop();

					if (visit[nodey][nodex] != 0) continue;

					visit[nodey][nodex] = ind;

					for (int k = 0; k <= 3; k++) {
						int nextx = nodex + distx[k];
						int nexty = nodey + disty[k];

						if (nextx <= 0 || nextx >= n + 1 || nexty <= 0 || nexty >= n + 1) continue;

						int data = abs(country[nexty][nextx] - ga);

						if (data >= l && data <= r) {
							Point nextpt;
							nextpt.x = nextx;
							nextpt.y = nexty;
							nextpt.node = country[nexty][nextx];
							q.push(nextpt);
						}
					}
				}

				ind++;
			}
		}

		int total[2501] = { 0, };
		int num[2501] = { 0, };

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int in = visit[i][j];
				total[in] = total[in] + country[i][j];
				num[in]++;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int in = visit[i][j];
				country[i][j] = total[in] / num[in];
			}
		}

		if (ind == n * n + 1) break;

		day++;
	}

	cout << day;

	return 0;
}
