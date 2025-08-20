#include <iostream>
#include <climits> // INT_MAX
#include <algorithm>  // sort
using namespace std;

int N, cntCoin, minMove = INT_MAX;
char grid[20][20];
pair<int, int> getCoin[3];
pair<int, int> S, E;
pair<int, pair<int, int>> coin[10];

void cal(int cnt, int pos){
    if(cnt == 3){
        int move = 0;
        int x = S.first, y = S.second;
        for(int i = 0; i < 3; i++){
            move += abs(getCoin[i].first - x) + abs(getCoin[i].second - y);
            x = getCoin[i].first;
            y = getCoin[i].second;
        }
        move += abs(E.first - x) + abs(E.second - y);
        minMove = min(minMove, move);
        return;
    }

    for(; pos < cntCoin; pos++){
        getCoin[cnt] = coin[pos].second;
        cal(cnt + 1, pos + 1);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') S = {i, j};
            else if(grid[i][j] == 'E') E = {i, j};
            else if(grid[i][j] != '.' ){
                coin[cntCoin++] = {grid[i][j], {i, j}};
            }
        }
    }
    sort(coin, coin + cntCoin);

    cal(0, 0);

    if(minMove==INT_MAX) minMove = -1;
    cout<<minMove;

    return 0;
}
