#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, cnt;
int grid[100][100];
int visited[100][100];

void dfs(int cx, int cy, int num){
    for(int i = 0; i < 4; i++){
        int x = cx + dx[i];
        int y = cy + dy[i];

        if(x < 0 || x >= N || y < 0 || y >= N) continue;
        if(!visited[x][y] && grid[x][y]==num){
            cnt++;
            visited[x][y]++;
            dfs(x, y, num);
        }
    }
}

int main() {
    cin>>N;
    for(int i = 0; i < N ;i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    int blockCnt = 0;
    int maxBlock = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                cnt = 1;
                visited[i][j]++;
                dfs(i, j, grid[i][j]);
                if(cnt>=4) blockCnt++;
                maxBlock = max(cnt, maxBlock);
            }
        }
    }

    cout<<blockCnt<<' '<< maxBlock;
    return 0;
}