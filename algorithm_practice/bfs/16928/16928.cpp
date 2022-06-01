#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int ladder[101];
int snake[101];

queue<pair<int, int > > q; //location, cnt

bool visit[101];

void push(int node, int ga, int cnt) {
	int nextnode;
	nextnode = node + ga;
	if (ladder[nextnode] != 0) nextnode = ladder[nextnode];
	else if (snake[nextnode] != 0) nextnode = snake[nextnode];
	q.push({ nextnode, cnt + 1 });
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a] = b;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		snake[a] = b;
	}

	q.push({1, 0});

	int answer = 1000000001;

	while (!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (node >= 100) {
			answer = cnt;
			break;
		}

		if (visit[node]) continue;

		visit[node] = true;

		push(node, 1, cnt);
		push(node, 2, cnt);
		push(node, 3, cnt);
		push(node, 4, cnt);
		push(node, 5, cnt);
		push(node, 6, cnt);
	}

	cout << answer;

	return 0;
}
