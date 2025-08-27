#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];
int visited[100][100]{};
vector<pair<int, int>> stone;
int maxcnt;

int bfs(int r, int c){
    queue<pair<int, int>> q;
    int cnt = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    q.push({r,c});
    if(visited[r][c]) return 0;
    visited[r][c]++;
    cnt++;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x >= n || y >= n || x < 0 || y < 0) continue;
            if(!visited[x][y] && !grid[x][y]){
                q.push({x, y});
                visited[x][y]++;
                cnt++;
            }
        }
    }

    return cnt;
}

void select_stone(int cnt, int pos){
    if(cnt==m){
        // for(int i = 0; i< n; i++){
        //     for(int j = 0; j< n; j++){
        //         cout<<grid[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';

        memset(visited, 0, sizeof(visited));
        int available = 0;
        for(int i = 0; i < k; i++){
            available += bfs(r[i], c[i]);
        }
        maxcnt = max(maxcnt, available);

        return;
    }

    for(int i = pos; i < (int)stone.size(); i++){
        grid[stone[i].first][stone[i].second]--;
        select_stone(cnt + 1, i + 1);
        grid[stone[i].first][stone[i].second]++;
    }
}


int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(grid[i][j]==1){
                stone.push_back({i, j});
            }
        }
    }

    select_stone(0, 0);

    cout<<maxcnt;

    return 0;
}
