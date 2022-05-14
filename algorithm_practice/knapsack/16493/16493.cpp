#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;

int day[21];
int page[21];
int dp[21][201];

int answer(){

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(j < day[i]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - day[i]] + page[i])));
        }
    }

    return dp[m][n];
}

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> day[i] >> page[i];
    }

    cout << answer();

    return 0;
}
