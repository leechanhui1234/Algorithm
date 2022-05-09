#include <iostream>
#include <cstdio>

using namespace std;

int testcase;
int num; //coin count
int coin[21];
int price;
int dp[21][10001];

void answer(){
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= price; j++){
            if(i == 1){
               if(j % coin[i] == 0) dp[i][j] = 1;
               else dp[i][j] = 0;
            } else {
                if(j == coin[i]) dp[i][j] = dp[i - 1][j] + 1;
                else if(j < coin[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]];
            }
        }
    }

    cout << dp[num][price] << '\n';
}

int main()
{
    cin >> testcase;
    for(int i = 1; i <= testcase; i++){
        cin >> num;

        for(int i = 1; i <= num; i++){
            cin >> coin[i];
        }

        cin >> price;

        answer();
    }
    return 0;
}
