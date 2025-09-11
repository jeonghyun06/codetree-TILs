#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int n, k, minTime = INT_MAX;
int grid[100][100];
int r1, c1, r2, c2;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0 ,-1, 0};

int bfs(int r, int c){
    queue<pair<int, int>> q;
    int visited[100][100]{};
    int step[100][100]{};

    q.push({r, c});
    visited[r][c]++;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x < 0 || y < 0 || x >= n || y >= n) continue;
            if(!visited[x][y] && !grid[x][y]){
                q.push({x, y});
                visited[x][y]++;
                step[x][y] = step[cx][cy] + 1;
            }
        }
        
    }

    return visited[r2][c2] ? step[r2][c2] : -1;
}

void selectWall(int cnt, int r, int c){
    if(cnt==k){
        int tmp = bfs(r1, c1);
        minTime = min(minTime, (tmp==-1) ? minTime : tmp);
        return;
    }

    for(int i = r; i < n; i++){
        int j;
        if(i==r) j = c;
        else j = 0;
        for(; j < n ; j++){
            if(grid[i][j]){
                grid[i][j]--;
                selectWall(cnt + 1, i, j + 1);
                grid[i][j]++;
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    selectWall(0, 0, 0);

    if(minTime==INT_MAX)
        cout<<-1;
    else cout<<minTime;

    return 0;
}
