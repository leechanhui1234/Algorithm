#include <iostream>
#include <cstdio>

using namespace std;

int topni[5][10];
int circle[5]; //-1 : ccw, 1 : cw

int main()
{
    for(int i = 0; i < 4; i++){
        char arr[10];

        cin >> arr;

        for(int j = 0; j < 8; j++){
            if(arr[j] == '1') topni[i][j] = 1;
            else topni[i][j] = 0;
        }
    }

    int num;

    cin >> num;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < 4; j++) circle[j] = 0; //init

        int n, m; //number, type

        cin >> n >> m;

        n -= 1; // index맞추기 위함

        circle[n] = m;

        for(int j = n - 1; j >= 0; j--){
            if(topni[j + 1][6] == topni[j][2]) circle[j] = 0;
            else circle[j] = circle[j + 1] * (-1);
        }

        for(int j = n + 1; j <= 3; j++){
            if(topni[j - 1][2] == topni[j][6]) circle[j] = 0;
            else circle[j] = circle[j - 1] * (-1);
        }

        for(int j = 0; j <= 3; j++){
            if(circle[j] == 0) continue; //회전 x

            int arr[10] = {0, };

            if(circle[j] == -1) { //ccw
                for(int k = 0; k <= 7; k++){
                    if(k == 7) arr[k] = topni[j][0];
                    else arr[k] = topni[j][k + 1];
                }
            }

            else {  //cw
                for(int k = 0; k <= 7; k++){
                    if(k == 0) arr[0] = topni[j][7];
                    else arr[k] = topni[j][k - 1];
                }
            }

            for(int k = 0; k <= 7; k++){
                topni[j][k] = arr[k];
            }
        }
    }

    int sum = 0;

    for(int i = 0; i <= 3; i++){
        int n = 1;

        if(topni[i][0] == 0) continue;

        for(int j = 0; j < i; j++){
            n *= 2;
        }

        sum += n;
    }

    cout << sum;
    return 0;
}
