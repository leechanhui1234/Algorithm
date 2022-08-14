#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

long long int number[1000010];

int m;
int ind = 0;

long long int answer[15];

long long int po(int n, int c){
    long long int result = 1;
    for(int i = 0; i < c; i++){
        result *= n;
    }

    return result;
}

void backtracking(int index, long long int num){
    if(index == m){
        long long int result = 0;
        int c = m - 1; //ÀÚ¸®
        for(int i = 0; i < m; i++){
            result = result + answer[i] * po(10, c);
            c--;
        }

        number[ind++] = result;
        return;
    }

    for(int i = 0; i < num; i++){
        answer[index] = i;
        backtracking(index + 1, i);
    }
}

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(number, number + 1000001, -1);

    for(int i = 1; i <= 10; i++){
        m = i;
        backtracking(0, 10);
    }

    int test;
    cin >> test;

    cout << number[test];

    return 0;
}
