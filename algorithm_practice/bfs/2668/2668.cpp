#include<iostream>
#include<cstdio>

using namespace std;

struct Coord {
	int str;
	int en;
};

Coord matrix[101];

int n;

int start;
bool check = false;

bool visit[101] = { false, };

int cnt = 0;
bool answer[101] = { false, };

void dfs(int n) {
	if (visit[n]) {
		if (n == start) check = true;

		return;
	}

	visit[n] = true;
	dfs(matrix[n].en);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int d;
		cin >> d;
		matrix[i].str = i;
		matrix[i].en = d;
	}

	for (int i = 1; i <= n; i++) {
		start = i;
		fill(visit, visit + n + 1, false);
		check = false;
		dfs(start);
		if (check) {
			answer[i] = true;
			cnt++;
		}
	}

	cout << cnt << '\n';

	for (int i = 1; i <= n; i++) {
		if (answer[i]) cout << i << '\n';
	}
	return 0;
}
