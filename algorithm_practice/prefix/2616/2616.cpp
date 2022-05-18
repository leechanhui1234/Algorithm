#include<iostream>
#include<cstdio>

using namespace std;

int n;

int arr[50001];
int dp[4][50001];
int prefix[50001];

int m;

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }

    cin >> m;

    for(int i = 1; i <= 3; i++){
        for(int j = i * m; j <= n; j++){
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + prefix[j] - prefix[j - m]);
        }
    }

    cout << dp[3][n];
    return 0;
}
