#include <iostream>
using namespace std;

int dx[3][4] = {{0, 0, 0, 0},
                {0, 1, 0, -1},
                {-1, 1, -1, 1}};

int dy[3][4] = {{2, 1, -1, -2},
                {1, 0, -1, 0},
                {1, 1, -1, -1}};

int n, cntMax, bombCnt;
int grid[20][20];
int boom[20][20];

void bomb(int b, int x, int y, int check){
    for(int i = 0; i < 4; i++){
        int cx = x + dx[b][i];
        int cy = y + dy[b][i];
        if(cx < 0  || cy < 0 || cx >= n || cy >=n) continue;
        boom[cx][cy] += check;
    }
}

void backtracing(int x, int y, int n){
    if(bombCnt<=n){
        cout<<x<<' '<<y;
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
                grid[i][j]--;
                boom[i][j]++;
                for(int k = 0; k < 3; k++){
                    bomb(k, i, j, 1);
                    backtracing(i, j, n + 1);
                    bomb(k, i, j, -1);

                }
                grid[i][j]++;
            }
        }
    }
    
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            bombCnt += grid[i][j];
        }
    }
    backtracing(0,0, 0);

    cout<<cntMax;

    return 0;
}
