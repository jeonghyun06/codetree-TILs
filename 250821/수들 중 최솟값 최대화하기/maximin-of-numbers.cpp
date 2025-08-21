#include <iostream>

using namespace std;

int n, maxMin;
int grid[10][10];
int visited[10];

void backtracking(int cnt, int mini){
    if(cnt==n){
        maxMin = max(maxMin, mini);
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        visited[i]++;
        backtracking(cnt + 1, min(mini, grid[cnt][i]));
        visited[i]--;
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    backtracking(0, 10000);

    cout<<maxMin;
    return 0;
}
