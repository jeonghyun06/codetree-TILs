#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int box[102][102];

int main() {
    int n, m;
    cin>>n>>m;

    int cnt=1;
    int dir=0;

    for(int i=0;i<=n+1;i++){
        box[i][m+1] = -1;
        box[i][0] = -1;
    }
    for(int i=0;i<=m+1;i++){
        box[n+1][i] = -1;
        box[0][i] = -1;
    }

    int x = 1, y = 1;
    while(cnt<=n*m){
        box[y][x] = cnt++;
        if(box[y + dy[dir]][x + dx[dir]] != 0) {
            dir = (dir+1) % 4;
        }
        x += dx[dir];
        y += dy[dir];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<box[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}