#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

long long int prefix[1000001];

int n;

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= 1000000; i++){

        for(int j = i; j <= 1000000; j = j + i){
            prefix[j] = prefix[j] + i;
        }

        prefix[i] = prefix[i - 1] + prefix[i];
    }

    cin >> n;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        cout << prefix[num] << '\n';
    }

    return 0;
}
