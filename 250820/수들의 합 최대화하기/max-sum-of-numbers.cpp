#include <iostream>

using namespace std;

int n, maxSum;
int visited[10];
int grid[10][10];

void cal(int cnt, int sum){
    if(cnt==n){
        maxSum = max(sum, maxSum);
        return;
    }
    for(int j = 0; j < n; j++){
        if(visited[j]) continue;
        visited[j]++;
        cal(cnt + 1, sum + grid[cnt][j]);

        visited[j]--;
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
