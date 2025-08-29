#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, k, u, d;
int grid[8][8];
vector<pair<int, int>> city;
int visited[8][8];
int maxCnt;

int bfs(int r, int c){
    if(visited[r][c]) return 0;

    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c]++;
    int cnt = 1;

    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = cx + dx[i], y = cy + dy[i];
            if(x >= n || y >= n || x < 0 || y < 0) continue;

            int diff = abs(grid[x][y]-grid[cx][cy]);
            if(!visited[x][y] && diff >= u && diff <= d){
                visited[x][y]++;
                q.push({x, y});
                cnt++;
            }
        }
    }
    return cnt;
}

// backtracking(도시선택) + bfs(갈 수 있는 도시)
void chooseCity(int cnt, int r, int c){
    if(cnt==k){
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for(int i = 0; i < k; i++){
            cnt += bfs(city[i].first, city[i].second);
        }

        maxCnt = max(cnt, maxCnt);
        return;
    }
    int j = c;
    for(int i = r; i < n; i++){
        for(; j < n; j++){
            city.push_back({i, j});
            chooseCity(cnt + 1, i, j + 1);
            city.pop_back();
        }
        j = 0;
    }
}


int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    chooseCity(0, 0, 0);

    cout<<maxCnt;

    return 0;
}
