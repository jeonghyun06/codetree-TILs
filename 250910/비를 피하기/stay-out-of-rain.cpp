#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, h, m;
int grid[100][100]; //1 == 벽, 2 == 사람, 3 == 가능, 0 == 이동가능
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int BFS(pair<int, int> pos){
    queue<pair<int, int>> path;
    int visited[100][100]{};
    int step[100][100]{};

    path.push(pos);
    visited[pos.first][pos.second]++;

    while(!path.empty()){
        int cx = path.front().first;
        int cy = path.front().second;
        path.pop();

        for(int i = 0; i < 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x < 0 || y < 0 || x >= n || y >= n) continue;
            if(visited[x][y] || grid[x][y] == 1) continue;
            
            step[x][y] = step[cx][cy] + 1;
            if(grid[x][y]==3) return step[x][y];

            visited[x][y]++;
            path.push({x, y});
        }
    }

    return -1;
}

int main() {
    cin >> n >> h >> m;
    vector<pair<int, int>> human;
    int time[100][100]{};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]==2)
                human.push_back({i, j});
        }
    }

    for(int i = 0; i < h; i++){
        time[human[i].first][human[i].second] = BFS(human[i]);
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<time[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
