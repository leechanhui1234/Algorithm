#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n, m;

int rain[501];

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> rain[i];
    }

    int answer = 0;

    while(1){
        bool check = true;

        for(int i = 2; i <= m - 1; i++){
            int l = -1, r = -1;

            for(int j = i - 1; j >= 1; j--){
                if(rain[j] > rain[i]){
                    l = j;
                    break;
                }
            }

            for(int j = i + 1; j <= m; j++){
                if(rain[j] > rain[i]){
                    r = j;
                    break;
                }
            }

            if(l == -1) continue;
            if(r == -1) continue;

            check = false;

            answer = answer + min(rain[l], rain[r]) - rain[i];
            rain[i] = min(rain[l], rain[r]);
            break;
        }

        if(check)  break;
    }

    cout << answer;
    return 0;
}
