#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int box[102][102];
int main() {
    int n, m;
    cin>>n>>m;

    for(int i=0;i<=n+1;i++){
        box[i][0] = -1;
        box[i][m+1] = -1;
    }

    for(int i=0;i<=m+1;i++){
        box[0][i] = -1;
        box[n+1][i] = -1;
    }

    int cnt = 1;
    int d = 0;
    int curX = 1;
    int curY = 1;
    while(cnt <= n*m){
        box[curY][curX] = cnt++;
        if(box[curY+dy[d]][curX+dx[d]] != 0){
            d = (d + 1) % 4;
        }
        curX += dx[d];
        curY += dy[d];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<box[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}