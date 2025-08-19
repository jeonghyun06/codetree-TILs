#include <iostream>
#include <vector>

using namespace std;

int n, m, c, maxSum, sum;
int weight[10][10];
int x, y;

void calSum(int i, int curW, int curV) {
    if (curW > c || i > m) return;
    sum = max(sum, curV);
    calSum(i + 1, curW, curV);
    calSum(i + 1, curW + weight[x][y + i], curV + weight[x][y + i] * weight[x][y + i]);
}

void bt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x = i;
            y = j;
            calSum(0, 0, 0);
            int squareSum = sum;
            int l = j + m;
            for (int k = i; k < n; k++) {
                for (; l < n; l++) {
                    x = k;
                    y = l;
                    sum = 0;
                    calSum(0, 0, 0);
                    int squareSum2 = sum;
                    maxSum = max(maxSum, squareSum + squareSum2);
                }
                l = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    bt();

    cout << maxSum;

    return 0;
}