#include <iostream>
using namespace std;

int map[1000][1000];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
    int n;
    cin>>n;

    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='/')
                map[i][j] = 0;
            else
                map[i][j] = 1;
        }
    }

    int k;
    cin>>k;
    int cnt=0;
    int dir = k/n; // d, l, u, r
    int x, y;
    if(dir==0) {
        x = k - 1;
        y = 0;
    }
    else if(dir==1){
        x = n-1;
        y = k%n;
    }
    else if(dir==2){
        x = n-k%n;
        y = n-1;
    }
    else {
        x = 0;
        y = 4*n-k;
    }
    while(x<n && x>=0 && y<n && y>=0){
        dir = 3-dir; // d -> r, l ->u, u -> l, r -> d
        if(map[y][x] == 0) dir = (dir + 2) % 4;
        x += dx[dir];
        y += dy[dir];
        cnt++;
    }

    cout<<cnt;
    return 0;
}