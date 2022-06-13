#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0 //존재할 수 없는 값

using namespace std;

int n;

long long int dp[100001][2];

int main() {

	cin >> n;

	dp[0][0] = 1;
	dp[0][1] = 1;

	bool check = true;

	for (int i = 1; i <= n; i++) {
		char arr1[5];
		char arr2[5];
		cin >> arr1 >> arr2;
		int n1 = arr1[1] - '0';
		int n2 = arr2[1] - '0';

		if (dp[i - 1][0] == INF) dp[i][0] = INF;
		else {
			long long int ans1 = 0;
			long long int ans2 = 0;
			long long int num = dp[i - 1][0];

			if (arr1[0] == '+') ans1 = num + n1;
			else if (arr1[0] == '-') ans1 = num - n1;
			else if (arr1[0] == '*') ans1 = num * n1;
			else ans1 = num / n1;

			if (arr2[0] == '+') ans2 = num + n2;
			else if (arr2[0] == '-') ans2 = num - n2;
			else if (arr2[0] == '*') ans2 = num * n2;
			else ans2 = num / n2;

			dp[i][0] = max(ans1, ans2);
			if (dp[i][0] <= 0) dp[i][0] = INF;
		}

		if(dp[i - 1][0] != INF) dp[i][1] = dp[i - 1][0];

		if (dp[i - 1][1] != INF) {
			long long int ans1 = 0;
			long long int ans2 = 0;
			long long int num = dp[i - 1][1];

			if (arr1[0] == '+') ans1 = num + n1;
			else if (arr1[0] == '-') ans1 = num - n1;
			else if (arr1[0] == '*') ans1 = num * n1;
			else ans1 = num / n1;

			if (arr2[0] == '+') ans2 = num + n2;
			else if (arr2[0] == '-') ans2 = num - n2;
			else if (arr2[0] == '*') ans2 = num * n2;
			else ans2 = num / n2;

			dp[i][1] = max(dp[i][1], max(ans1, ans2));
			if (dp[i][1] <= 0) dp[i][1] = INF;
		}

		if (dp[i][0] == INF && dp[i][1] == INF) {
			check = false;
			break;
		}
	}

	if (check) {
		cout << max(dp[n][0], dp[n][1]);
	}
	else {
		cout << "ddong game";
	}
	return 0;
}
