#include <iostream>
using namespace std;

int dx[3][4] = {{0, 0, 0, 0},
                {0, 1, 0, -1},
                {-1, 1, -1, 1}};

int dy[3][4] = {{2, 1, -1, -2},
                {1, 0, -1, 0},
                {1, 1, -1, -1}};

int n, cntMax;
int grid[20][20];
int boom[20][20];

void backtracing(int x, int y);

void bomb(int b, int x, int y){
    for(int i = 0; i < 4; i++){
        int cx = x + dx[b][i];
        int cy = y + dy[b][i];
        if(cx < 0  || cy < 0 || cx >= n || cy >=n) continue;
        boom[cx][cy]++;
    }
    backtracing(x+1, y+1);
    for(int i = 0; i < 4; i++){
        int cx = x + dx[b][i];
        int cy = y + dy[b][i];
        if(cx < 0  || cy < 0 || cx >= n || cy >=n) continue;
        boom[cx][cy]--;
    }
}

void backtracing(int x, int y){
    if(x==n && y==n){
        int cnt=0;
        for(int i = 0; i < n; i++){
            for(int j  = 0; j < n; j++) {
                if(boom[i][j]) cnt++;
            }
        }
        cntMax = max(cnt, cntMax);
        return;
    }
    for(int i = x;  i < n; i++){
        for(int j = y; j < n; j++){
            if(grid[i][j]==1) {
                boom[i][j]++;
                bomb(1, i, j);
                bomb(2, i, j);
                bomb(3, i, j);
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    backtracing(0,0);

    cout<<cntMax;

    return 0;
}
