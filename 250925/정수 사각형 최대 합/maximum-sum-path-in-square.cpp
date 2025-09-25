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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] += max(i>0 ? grid[i-1][j]: 0, j>0 ? grid[i][j-1] : 0);
        }
    }

    cout<<grid[n-1][n-1];
    return 0;
}
