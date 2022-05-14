#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;

long long int arr[100001];
long long int segment[500001]; //높이 최솟값을 가지는 인덱스
long long int ans = 0;

long long int init(int left, int right, int node){
    if(left >= right) return segment[node] = left;

    int mid = (left + right) / 2;
    long long int lind = init(left, mid, 2 * node);
    long long int rind = init(mid + 1, right, 2 * node + 1);
    if(arr[lind] > arr[rind]) return segment[node] = rind;
    else return segment[node] = lind;
}

long long int calculator(int left, int right, int str, int en, int node){
    if(left > en || right < str) return 0;

    if(str <= left && right <= en) return segment[node];

    int mid = (left + right) / 2;

    long long int lind = calculator(left, mid, str, en, 2 * node);
    long long int rind = calculator(mid + 1, right, str, en, 2 * node + 1);

    if(lind == 0) return rind;
    if(rind == 0) return lind;
    if(arr[lind] < arr[rind]) return lind;
    else return rind;
}

void query(int left, int right, int str, int en){

    if(str > en) return;
    if(en == str){
        if(ans < arr[str]) ans = arr[str];
        return;
    }

    long long int node = calculator(left, right, str, en, 1);

    long long int data = arr[node] * (en - str + 1);

    if(ans < data) ans = data;

    query(left, right, str, node - 1);
    query(left, right, node + 1, en);
}

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> n;

        if(n == 0) break;

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        init(1, n, 1);

        ans = 0;

        query(1, n, 1, n);

        cout << ans << '\n';
    }

    return 0;
}
