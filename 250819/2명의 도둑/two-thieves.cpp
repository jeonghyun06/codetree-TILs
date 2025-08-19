#include <iostream>
#include <vector>

using namespace std;

int n, m, c, maxSum;
int weight[10][10];
pair<int, int> thives[3];

// 도둑은 2명 -> 겹칠 수 없음
// 한 row에서 연속되게 고를 수 있음 각각 합이 C 이하
// 가치는 w^2

void bt() {
    // 한 열에서 m개 선택. c 이상이면 그 이전까지 계산 
    // 하나 pop하고 다음꺼 push c 이상인지 봄 -> 
    // m개씩 두 쌍 선택 완료 -> 제곱 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int squareSum = 0;
            int sum = 0;
            for (int t = 0; t < m; t++) {
                sum += weight[i][j + t];
                if (sum > c) break;
                squareSum += weight[i][j + t] * weight[i][j + t];
            }
            int l = j + m;
            for (int k = i; k < n; k++) {
                for (; l < n; l++) {
                    sum = 0;
                    int squareSum2 = 0;
                    for (int t = 0; t < m; t++) {
                        sum += weight[k][l + t];
                        if (sum > c) break;
                        squareSum2 += weight[k][l + t] * weight[k][l + t];
                    }
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