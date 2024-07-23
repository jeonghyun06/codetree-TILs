#include <iostream>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int box[102][102];

int main() {
    int n;
    cin>>n;

    for(int i=0;i<=n+1;i++){
        box[0][i]=-1;
        box[i][0]=-1;
        box[n+1][i]=-1;
        box[i][n+1]=-1;
    }

    int cnt = n*n;
    int x = n;
    int y = n;
    int dir = 0;

    int num = 1;
    while(cnt>0){
        box[y][x] = cnt--;
        if(box[y+dy[dir]][x+dx[dir]]!= 0){
            dir = (dir+1)%4;
        }
        x += dx[dir];
        y += dy[dir];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<box[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}