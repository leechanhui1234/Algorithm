#include<iostream>
#include<cstdio>

using namespace std;

int n, m;

long long int arr[1000001];
long long int mod[1001];
long long int prefix[1000001];

long long int combi(long long int d){
    return d * (d - 1) / 2;
}
int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    mod[0] = 1;

    for(int i = 1; i <= n; i++){
        prefix[i] = ((prefix[i - 1] % m) + (arr[i] % m)) % m;
        mod[prefix[i] % m]++;
    }

    long long int ans = 0;

    for(int i = 0; i < m; i++){
        ans = ans + combi(mod[i]);
        //cout << "ans : " << ans << " " << "mod : " << mod[i] << endl;
    }

    cout << ans;
    return 0;
}
