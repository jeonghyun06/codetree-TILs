#include <iostream>
#include <climits>
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
        grid[i][n-1] += grid[i-1][n-1];
    }
    for(int i = n-2; i >= 0; i--){
        grid[0][i] += grid[0][i + 1];
    }

    for(int i = 1; i < n; i++){
        for(int j = n - 2; j >= 0; j--){
            grid[i][j] += min(grid[i - 1][j], grid[i][j + 1]);
        }
    }

    cout<<grid[n-1][0];

    return 0;
}
