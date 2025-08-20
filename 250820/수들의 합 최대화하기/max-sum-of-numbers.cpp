#include <iostream>

using namespace std;

int n, maxSum;
int visited[2][10];
int grid[10][10];

void cal(int cnt, int sum){
    if(cnt==n){
        maxSum = max(sum, maxSum);
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[0][i] || visited[1][j]) continue;
            visited[0][i]++;
            visited[1][j]++;
            cal(cnt + 1, sum + grid[i][j]);

            visited[0][i]--;
            visited[1][j]--;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cal(0, 0);
    
    cout<<maxSum;

    return 0;
}
