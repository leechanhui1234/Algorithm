#include<iostream>
#include<cstdio>

using namespace std;

int dp[201][101]; //(공차*숫자)
int n;
bool check[101];
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int num = arr[1];
	check[num] = true;

	int answer = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 100; j++) {
			if (!check[j]) continue;
			int d = arr[i] - j + 100; //공차가 음수인 경우 방지
			num = dp[d][arr[i]];
			if (num == 0) num += 2;
			dp[d][arr[i]] = max(num, dp[d][j] + 1);
			if (answer < dp[d][arr[i]]) answer = dp[d][arr[i]];
		}
		check[arr[i]] = true;
	}

	cout << answer;

	return 0;
}
