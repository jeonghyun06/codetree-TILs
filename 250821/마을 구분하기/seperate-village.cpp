#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;
int grid[25][25];
int visited[25][25];
vector<int> town;

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];

        if(cx < 0 || cy < 0 || cx >= N || cy >= N) continue;
        if(grid[cx][cy]){
            town[town.size()-1]++;
            grid[cx][cy]--;
            dfs(cx, cy);
        }

    }
}

int main() {

    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>grid[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!grid[i][j]) continue;
            town.push_back(1);
            grid[i][j]--;
            dfs(i, j);
        }
    }
    
    cout<<town.size()<<'\n';

    sort(town.begin(), town.end());

    for(int p: town){
        cout<<p<<'\n';
    }

    return 0;
}