#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, k;
int grid[100][100];
int r, c;


pair<int, int> bfs(int r, int c){
    queue<pair<int,int>> q;
    int visited[100][100]{};

    q.push({r, c});
    visited[r][c]++;

    int maxNum=0;
    pair<int, int> maxPos = {n, n};

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();
        
        for(int i = 0; i < 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x >= n || y >= n || x < 0 || y < 0) continue;
            if(!visited[x][y] && grid[x][y] < grid[r][c]){ // 자신보다 작은 위치로 이동
                // cout<<'('<<x<<", "<<y<<')'<<grid[x][y]<<"\n";
                if(maxNum < grid[x][y] || (maxNum==grid[x][y] && maxPos > make_pair(x, y))){ //최대 숫자 및 행/열 번호가 제일 작은 위치
                    maxPos.first = x; maxPos.second = y;
                    maxNum = grid[x][y];
                }
                
                q.push({x, y});
                visited[x][y]++;
            }
        }
    }
    // cout<<maxNum<<' '<<maxPos.first<<' '<<maxPos.second<<'\n';

    if(maxPos==make_pair(n, n)) return {r, c};
    return maxPos;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    pair<int, int> pos = {r-1, c-1};
    
    for(int i = 0; i < k; i++){
        
        pos = bfs(pos.first, pos.second);
    }

    cout<< pos.first + 1 << ' '<< pos.second + 1;
    return 0;
}
