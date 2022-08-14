#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;

long long int arr[100001];
long long int arr2[100001];

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i == 0) continue;
        arr2[i - 1] = arr[i];
    }

    sort(arr2, arr2 + n - 1);

    bool check = true;

    long long int s = arr[0];

    for(int i = 0; i < n - 1; i++){
        if(s > arr2[n - 2]) break;
        if(i == n - 2){
            check = false;
            break;
        }
        if(s <= arr2[i]){
            check = false;
            break;
        }
        s = s + arr2[i];
    }

    if(check) cout << "Yes";
    else cout << "No";
    return 0;
}
