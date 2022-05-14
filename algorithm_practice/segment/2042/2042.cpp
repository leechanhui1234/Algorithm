#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
long long int arr[1000001];
long long int segment[5000001];

long long int init(int left, int right, int node){
    if(left >= right) return segment[node] = arr[right];
    int mid = (left + right) / 2;
    long long int lsum = init(left, mid, node * 2);
    long long int rsum = init(mid + 1, right, node * 2 + 1);
    return segment[node] = lsum + rsum;
}

void change(int left, int right, int index, long long int diff, int node){
    if(left > index || right < index) return;

    segment[node] = segment[node] + diff;

    if(right == left){
        return;
    }

    int mid = (left + right) / 2;
    change(left, mid, index, diff, 2 * node);
    change(mid + 1, right, index, diff, 2 * node + 1);
}

long long int calculator(int left, int right, int str, int en, int node){
    if(left > en || right < str) return 0;

    if(str <= left && right <= en) return segment[node];

    int mid = (left + right) / 2;

    long long int lsum = calculator(left, mid, str, en, 2 * node);
    long long int rsum = calculator(mid + 1, right, str, en, 2 * node + 1);
    return lsum + rsum;
}

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    init(1, n, 1);

    for(int i = 1; i <= m + k; i++){
        long long int type, a, b;

        cin >> type >> a >> b;

        if(type == 1){
            long long int diff = b - arr[a];
            arr[a] = b;
            change(1, n, a, diff, 1);
        }

        else if(type == 2){
            cout << calculator(1, n, a, b, 1) << '\n';
        }
    }
    return 0;
}
