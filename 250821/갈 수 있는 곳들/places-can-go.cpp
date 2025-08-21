#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, K;
int grid[101][101];
int visited[101][101];
queue<pair<int, int>> start;

int main() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> grid[i][j];
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < K; i++){
        int r, c;
        cin >> r >> c;
        start.push({r,c});
        visited[r][c]++;
        cnt++;
    }

    
    while(!start.empty()){
        int cx = start.front().first;
        int cy = start.front().second;
        start.pop();

        for(int i = 0; i < 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];
            
            if(x <= 0 || y <= 0 || x > N || y > N) continue;
            if(!visited[x][y] && !grid[x][y]){
                visited[x][y]++;
                start.push({x, y});
                cnt++;
            }
        }
    }

    cout<<cnt;
    return 0;
}