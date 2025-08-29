#include <iostream>
#include <queue>
using namespace std;

int N, M;
int a[200][200];

int bfs(int r, int c){
    queue<pair<int, int>> q;
    int visited[200][200]{};

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int cnt = 0;

    q.push({r, c});
    visited[r][c]++;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for(int i =0; i < 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x >= N || y >= M || x < 0 || y < 0) continue;
            if(!visited[x][y]){
                if(a[x][y]){
                    cnt++;
                    a[x][y]--;
                }
                else{
                    q.push({x, y});
                }
                visited[x][y]++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    int curCnt = bfs(0,0);
    int befCnt = curCnt;
    int time = 0;

    while(curCnt){
        befCnt = curCnt;
        curCnt = bfs(0,0);
        time++;
    }

    cout<<time<<' '<<befCnt;
    return 0;
}
