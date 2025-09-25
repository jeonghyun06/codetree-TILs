#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    grid[0][1] = grid[1][0] = grid[1][1];
    for(int i = 2; i <= n; i++){
        grid[0][i] = min(grid[1][i - 1], grid[1][i]);
        grid[i][0] = min(grid[i - 1][1], grid[i][1]);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            grid[i][j] = min(max(grid[i-1][j], grid[i][j-1]), grid[i][j]);
        }
    }
    
    cout<<grid[n][n];

    return 0;
}
