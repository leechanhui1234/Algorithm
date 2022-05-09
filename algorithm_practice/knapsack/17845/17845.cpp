#include <iostream>
#include <cstdio>

using namespace std;

int n, k;
int infor[1001];
int prac[1001];
int dp[1001][10001];

int solution(){
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if(j < prac[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prac[i]] + infor[i]);
        }
    }

    return dp[k][n];
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= k; i++){
        cin >> infor[i] >> prac[i];
    }

    cout << solution();
    return 0;
}
