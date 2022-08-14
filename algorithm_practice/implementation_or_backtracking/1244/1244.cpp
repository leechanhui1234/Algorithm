#include<iostream>
#include<cstdio>

using namespace std;

int num;

int stateswitch[101];

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;

    for(int i = 1; i <= num; i++){
        cin >> stateswitch[i];
    }

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            for(int j = b; j <= num; j = j + b){
                if(stateswitch[j] == 0) stateswitch[j] = 1;
                else stateswitch[j] = 0;
            }
        }

        else {
            int ind1 = b;
            int ind2 = b;
            while(1){
                if(ind1 <= 0) break;
                if(ind2 > num) break;

                if(stateswitch[ind1] != stateswitch[ind2]) break;

                if(ind1 == ind2){
                    if(stateswitch[ind1] == 1) stateswitch[ind1] = 0;
                    else stateswitch[ind1] = 1;
                }

                else {
                    if(stateswitch[ind1] == 1) stateswitch[ind1] = 0;
                    else stateswitch[ind1] = 1;

                    if(stateswitch[ind2] == 1) stateswitch[ind2] = 0;
                    else stateswitch[ind2] = 1;
                }

                ind1--;
                ind2++;
            }
        }
    }

    for(int i = 1; i <= num; i++){
        if(i % 20 != 0) cout << stateswitch[i] << ' ';
        else cout << stateswitch[i] << '\n';
    }
    return 0;
}
