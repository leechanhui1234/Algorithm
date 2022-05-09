#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int c, n;
int cost[21]; //비용
int person[21]; //고객의 수
int dp[21][2000];
int finish;

int answer(){
    int m = 1000000001;
    for(int i = c; i <= finish; i++){
        if(dp[n][i] == 0) continue;
        else m = min(m, dp[n][i]);
    }
    return m;
}

void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= finish; j++){
            if(j < person[i]) dp[i][j] = dp[i - 1][j];
            else if(j == person[i] && dp[i - 1][j] != 0) dp[i][j] = min(dp[i - 1][j], cost[i]);
            else if(j == person[i] && dp[i - 1][j] == 0) dp[i][j] = cost[i];
            else if(dp[i - 1][j] != 0 && dp[i][j - person[i]] != 0) dp[i][j] = min(dp[i - 1][j], dp[i][j - person[i]] + cost[i]);
            else if(dp[i - 1][j] != 0) dp[i][j] = dp[i - 1][j];
            else if(dp[i][j - person[i]] != 0) dp[i][j] = dp[i][j - person[i]] + cost[i];
            else continue;
        }
    }
    cout << answer();
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> n;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> cost[i] >> person[i];
        if(c % person[i] == 0){
            t = c / person[i];
        } else {
            t = c / person[i] + 1;
        }
        if(finish < (person[i] * t)) finish = person[i] * t;
    }

    solve();

    return 0;
}
