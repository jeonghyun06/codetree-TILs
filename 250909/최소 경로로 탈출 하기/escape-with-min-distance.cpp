#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int n, m;
int a[100][100];
int step[100][100];

void BFS(int x, int y){
    queue<pair<int, int>> path;
    int visited[100][100]{};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    visited[x][y]++;
    path.push({x, y});

    while(!path.empty()){
        int cx = path.front().first;
        int cy = path.front().second;
        path.pop();

        for(int i = 0; i < 4; i++){
            int x = cx + dx[i];;
            int y = cy + dy[i];

            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(visited[x][y] || !a[x][y]) continue;
            path.push({x, y});
            visited[x][y]++;
            step[x][y] = step[cx][cy] + 1;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    BFS(0, 0);

    cout<<step[n-1][m-1];
    return 0;
}
