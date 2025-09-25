#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i < n; i++){
        grid[0][i] = min(grid[0][i - 1], grid[0][i]);
        grid[i][0] = min(grid[i - 1][0], grid[i][0]);
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            grid[i][j] = min(max(grid[i-1][j], grid[i][j-1]), grid[i][j]);
        }
    }
    
    cout<<grid[n-1][n-1];

    return 0;
}
