#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

long long int n;
long long int dp[5][100001];
char arr[100001];
char str[5] = "DKSH";

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cin >> arr;

    for(int i = 1; i <= n; i++){
        if(arr[i - 1] == 'D') dp[1][i] = dp[1][i - 1] + 1;
        else dp[1][i] = dp[1][i - 1];
    }

    for(int i = 2; i <= 4; i++){
        for(int j = 1; j <= n; j++){
            if(arr[j - 1] == str[i - 1])    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            else dp[i][j] = dp[i][j - 1];
        }
    }

    cout << dp[4][n];

    return 0;
}
