#include <iostream>
using namespace std;

char box[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=0;i<=n+1;i++){
        box[i][0] = 'A';
        box[i][m+1] = 'A';
    }
    for(int i=0;i<=m+1;i++){
        box[0][i] = 'A';
        box[n+1][i] = 'A';
    }

    int dir = 0;
    int x=1, y=1;

    int cnt=0;
    char cur = 'A';
    while(++cnt<=n*m){
        box[y][x] = cur++;
        if(box[y+dy[dir]][x+dx[dir]] != 0){
            dir = (dir+1) % 4;
        }
        if(cur>'Z') cur = 'A';
        
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