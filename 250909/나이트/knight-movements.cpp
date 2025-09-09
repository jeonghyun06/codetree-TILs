#include <iostream>
#include <queue>
using namespace std;

int n;
int r1, c1, r2, c2;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int step[100][100]{};


void BFS(int x, int y){
    queue<pair<int, int>> knight;
    int visited[100][100]{};

    knight.push({x, y});
    visited[x][y]++;
    
    while(!knight.empty()){
        int cx = knight.front().first;
        int cy = knight.front().second;
        knight.pop();

        for(int i = 0; i < 8; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(x >= n || y >= n || x < 0 || y < 0) continue;
            if(!visited[x][y]){
                visited[x][y]++;
                knight.push({x, y});
                step[x][y] = step[cx][cy] + 1;
            }
            if(x == r2-1 && y == c2-1) break;
        }
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    step[r2-1][c2-1] = -1;
    BFS(r1-1, c1-1);

    cout<<step[r2-1][c2-1];

    return 0;
}
