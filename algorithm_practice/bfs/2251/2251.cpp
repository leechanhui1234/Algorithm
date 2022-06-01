#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Water {
	int a;
	int b;
	int c;
};

bool visit[201][201][201];

int answer[201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;

	cin >> A >> B >> C;

	Water w;
	w.a = 0, w.b = 0, w.c = C;

	queue<Water> q;
	q.push(w);

	while (!q.empty()) {
		int nodea = q.front().a;
		int nodeb = q.front().b;
		int nodec = q.front().c;
		q.pop();

		if (visit[nodea][nodeb][nodec]) continue;

		//cout << nodea << ' ' << nodeb << ' ' << nodec << endl;

		visit[nodea][nodeb][nodec] = true;

		if(nodea == 0) answer[nodec] = 1;

		if (nodeb + nodea <= B) q.push({ 0, nodea + nodeb, nodec });
		else q.push({nodea - (B - nodeb), B, nodec});

		if (nodea + nodec <= C) q.push({ 0, nodeb, nodea + nodec });
		else q.push({nodea - (C - nodec), nodeb, C});

		if (nodea + nodeb <= A) q.push({ nodea + nodeb, 0, nodec });
		else q.push({A, nodeb - (A - nodea), nodec});

		if (nodeb + nodec <= C) q.push({ nodea, 0, nodeb + nodec });
		else q.push({ nodea, nodeb - (C - nodec), C });

		if (nodea + nodec <= A) q.push({ nodea + nodec, nodeb, 0 });
		else q.push({ A, nodeb, nodec - (A - nodea) });

		if (nodeb + nodec <= B) q.push({ nodea, nodeb + nodec, 0 });
		else q.push({ nodea, B, nodec - (B - nodeb) });
	}

	for (int i = 0; i <= 200; i++) {
		if (answer[i] == 1) cout << i << ' ';
	}
	return 0;
}
