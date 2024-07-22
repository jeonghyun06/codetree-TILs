#include <iostream>
using namespace std;

int grid[102][102];
int dx[4] = {0,1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool func(int r, int c){
    int cnt = 0;
    for(int i=0;i<4;i++){
        if(grid[r+dy[i]][c+dx[i]]) cnt++;
    }
    if (cnt==3) return true;
    else return false;
}

int main() {
    int n, m;
    cin>>n>>m;

    int r, c;
    while(m--){
        cin>>r>>c;

        grid[r][c]++;
        if(func(r, c)) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    

    return 0;
}