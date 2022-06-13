#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int n;

double number[10001];
double dp[10001];
double answer;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> number[i];
	}

	dp[1] = number[1];
	answer = dp[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] * number[i], number[i]);
		if (answer < dp[i]) answer = dp[i];
	}

	printf("%.3f", answer);
	return 0;
}
