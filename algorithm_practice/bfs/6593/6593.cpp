#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

struct Point {
	int x;
	int y;
	int z;
	int cnt;
};

int l, r, c;

int startl, startr, startc;
int endle, endr, endc;

int stair[40][40][40];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				char arr[40];
				cin >> arr;
				for (int k = 0; k < strlen(arr); k++) {
					if (arr[k] == 'S') {
						startl = i;
						startr = j;
						startc = k + 1;
						stair[i][j][k + 1] = 1; //시작점
					}
					else if (arr[k] == '.') {
						stair[i][j][k + 1] = 0; //갈 수 있는 점
					}
					else if (arr[k] == '#') {
						stair[i][j][k + 1] = -1; //갈 수 없는 점
					}
					else {
						endle = i;
						endr = j;
						endc = k + 1;
						stair[i][j][k + 1] = 2; // 끝점
					}
				}
			}
		}

		queue<Point> q;

		q.push({ startc, startr, startl, 0 });

		int answer = -1;

		bool visit[40][40][40] = { false, };

		while (!q.empty()) {
			int nodex = q.front().x;
			int nodey = q.front().y;
			int nodez = q.front().z;
			int count = q.front().cnt;

			q.pop();

			if (visit[nodex][nodey][nodez]) continue;

			visit[nodex][nodey][nodez] = true;

			if (stair[nodez][nodey][nodex] == 2) {
				answer = count;
				break;
			}

			if (nodex + 1 <= c && stair[nodez][nodey][nodex + 1] != -1) q.push({ nodex + 1, nodey, nodez, count + 1 });
			if (nodey + 1 <= r && stair[nodez][nodey + 1][nodex] != -1) q.push({ nodex, nodey + 1, nodez, count + 1 });
			if (nodez + 1 <= l && stair[nodez + 1][nodey][nodex] != -1) q.push({ nodex, nodey, nodez + 1, count + 1 });
			if (nodex - 1 >= 1 && stair[nodez][nodey][nodex - 1] != -1) q.push({ nodex - 1, nodey, nodez, count + 1 });
			if (nodey - 1 >= 1 && stair[nodez][nodey - 1][nodex] != -1) q.push({ nodex, nodey - 1, nodez, count + 1 });
			if (nodez - 1 >= 1 && stair[nodez - 1][nodey][nodex] != -1) q.push({ nodex, nodey, nodez - 1, count + 1 });
		}

		if (answer != -1) printf("Escaped in %d minute(s).\n", answer);
		else printf("Trapped!\n");
	}

	return 0;
}
