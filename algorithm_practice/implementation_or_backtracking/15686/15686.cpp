#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n, m;
int index;

struct Point {
    int x;
    int y;
};

vector<Point> house;
Point chicken[15];
int choose[15];
int answer = 987654321;

void backtracking(int ind, int num){
    if(ind == m){
        int ans = 0;

        for(int i = 0; i < house.size(); i++){
            int mi = 987654321;
            for(int j = 0; j < m; j++){
                int in = choose[j];

                if(mi > (abs(house[i].x - chicken[in].x) + abs(house[i].y - chicken[in].y))){
                    mi = (abs(house[i].x - chicken[in].x) + abs(house[i].y - chicken[in].y));
                }
            }
            ans += mi;
        }

        if(answer > ans) answer = ans;

        return;
    }
    for(int i = num; i < index; i++){
        choose[ind] = i;
        backtracking(ind + 1, i + 1);
    }
}

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int num;
            cin >> num;
            if(num == 0) continue;
            else if(num == 1){
                house.push_back({j, i});
            }
            else{
                chicken[index].x = j;
                chicken[index].y = i;
                index++;
            }
        }
    }

    backtracking(0, 0);

    cout << answer;
    return 0;
}
