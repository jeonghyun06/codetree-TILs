#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int box[102][102];

int main() {
    int n;
    cin>>n;

    int cnt = 1;
    int x = n/2;
    int y = n/2;
    int dir = 0;
    int num=1, check=2;

    box[y][x] = cnt++;
    x += dx[dir];
    y += dy[dir];

    while(cnt<=n*n){
        box[y][x] = cnt++;
        check++;
        if(num <= check) {
            if(num!=n){
                num++;
            }
            check=1;
            dir = (dir+1)%4;
        }
        x += dx[dir];
        y += dy[dir];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<box[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}