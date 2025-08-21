#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M;
int grid[100][100];
int visited[100][100];
queue<pair<int,int>> path;

void bfs(){
    while(!path.empty()){
        int cx = path.front().first;
        int cy = path.front().second;
        path.pop();

        for(int i = 0; i < 4; i++) {
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x < 0 || y < 0 || x >= N || y >=M) continue;
            if(!visited[x][y] && grid[x][y]){
                visited[x][y]++;
                path.push({x, y});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    path.push({0,0});
    bfs();

    cout<<visited[N-1][M-1];
    return 0;
}