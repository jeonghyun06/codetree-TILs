#include <iostream>
#include <queue>
using namespace std;

int n, k;
int grid[100][100];
int step[100][100];
int visited[100][100];
queue<pair<int, int>> tangerine;

void bfs(){
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!tangerine.empty()){
        int cx = tangerine.front().first;
        int cy = tangerine.front().second;
        tangerine.pop();

        for(int i = 0; i < 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x < 0 || y < 0 || x >= n || y >= n) continue;
            if(!visited[x][y] && grid[x][y]==1){
                visited[x][y]++;
                tangerine.push({x, y});
                step[x][y] = step[cx][cy] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j]==2){
                tangerine.push({i, j});
                visited[i][j]++;
            }
        }
    }

    bfs();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]==0)
                cout<<-1<<' ';
            else if(visited[i][j]==0)
                cout<<-2<<' ';
            else cout<<step[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
