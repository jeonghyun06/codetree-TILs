#include <iostream>
using namespace std;

int box[100][100];
int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {-1, 0, 1, 0};

int main() {
    int n, t;
    cin>>n>>t;

    string o;
    cin>>o;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>box[i][j];
        }
    }

    int x = n/2;
    int y = n/2;
    int dir = 0;
    int cnt = box[x][y];

    for(int i=0;i<t;i++){
        if(o[i]=='L'){
            dir = (dir + 1) % 4;
        }
        else if(o[i]=='R'){
            dir = (dir + 3) % 4;
        }
        else{
            if(x + dx[dir] >= n || x + dx[dir] < 0 || y + dy[dir] >= n || y + dy[dir] < 0){
                continue;
            }

            x += dx[dir];
            y += dy[dir];
            cnt += box[y][x];
        }
    }

    cout<<cnt;

    return 0;
}