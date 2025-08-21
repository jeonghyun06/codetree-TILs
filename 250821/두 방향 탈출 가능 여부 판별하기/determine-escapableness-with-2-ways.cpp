#include <iostream>
using namespace std;

int N, M;
int grid[101][101];
int visited[101][101];
int isPossible;

void path(int x, int y){
    if(x==N-1 && y==N-1){
        isPossible++;
        return;
    }
    if(x + 1 < N && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
        visited[x + 1][y];
        path(x + 1, y);
    }
    if(y + 1 < N && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
        visited[x][y + 1];
        path(x, y + 1);
    }
}

int main() {

    cin>> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>grid[i][j];
        }
    }

    path(0,0);
    cout<<isPossible;
    return 0;
}