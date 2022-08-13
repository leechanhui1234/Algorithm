#include<iostream>
#include<cstdio>

using namespace std;

int n, k;
int pie[200010];

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> pie[i];
        pie[n + i] = pie[i];
    }

    int answer = 0;
    int prefix = 0;

    for(int i = 1; i <= k; i++){
        prefix = prefix + pie[i];
    }

    answer = prefix;

    for(int i = 2; i <= n; i++){
        prefix = prefix + pie[k + i - 1] - pie[i - 1];
        if(answer < prefix) answer = prefix;
    }

    cout << answer;
    return 0;
}
