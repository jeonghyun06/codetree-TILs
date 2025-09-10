#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, h, m;
int grid[100][100]; //1 == 벽, 2 == 사람, 3 == 가능, 0 == 이동가능
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> path;
int visited[100][100]{};
int step[100][100]{};
int leng[100][100]{};

void BFS(){
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
            visited[x][y]++;
            path.push({x, y});
        }
    }
}

int main() {
    cin >> n >> h >> m;
    vector<pair<int, int>> shelter;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]==3)
                shelter.push_back({i, j});
        }
    }

    for(int i = 0; i < m; i++){
        path.push(shelter[i]);
        visited[shelter[i].first][shelter[i].second]++;
    }

    BFS();

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!step[i][j] && grid[i][j]==2)
                step[i][j] = -1;
            else if(grid[i][j]!=2)
                step[i][j] = 0;
                
            cout<<step[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
