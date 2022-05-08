#include <iostream>
#include <cstdio>

using namespace std;

int num; //추의 개수

int weight[31]; //추의 무게

int dp[31][40001]; //추의 개수 * 확인할 무게

void answer(){
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= 40000; j++){
            if(dp[i - 1][j] == 1) dp[i][j] = 1;
            if(j == weight[i]) {if(j + weight[i] <= 40000 && dp[i - 1][j] == 1) dp[i][j + weight[i]] = 1;
                if(dp[i - 1][j] == 1) dp[i][weight[i] - j] = 1;
                dp[i][j] = 1;
                if(j + weight[i] <= 40000 && dp[i - 1][j] == 1) dp[i][j + weight[i]] = 1;
            }
            else if(j < weight[i]){
                if(j + weight[i] <= 40000 && dp[i - 1][j] == 1) dp[i][j + weight[i]] = 1;
                if(dp[i - 1][j] == 1) dp[i][weight[i] - j] = 1;
            }
            else {
                if(j + weight[i] <= 40000 && dp[i - 1][j] == 1) dp[i][j + weight[i]] = 1;
                if(dp[i - 1][j] == 1) dp[i][j - weight[i]] = 1;
            }
        }
    }
}

int check(int n){
    if(dp[num][n] == 1) return 1;
    else return 0;
}

int main()
{
    cin >> num;

    for(int i = 1; i <= num; i++){
        cin >> weight[i];
    }

    answer();

    int n; //질의어 수

    cin >> n;

    int ans;

    for(int i = 1; i <= n; i++){
        cin >> ans;
        if(check(ans) == 1) cout << 'Y' << ' ';
        else cout << 'N' << ' ';
    }
    return 0;
}
