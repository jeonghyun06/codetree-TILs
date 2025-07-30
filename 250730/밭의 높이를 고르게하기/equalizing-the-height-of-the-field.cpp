#include <iostream>

using namespace std;

int N, H, T;
int arr[100];

int main() {
    cin >> N >> H >> T; // N개 중 H 높이 T번 이상
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int minSum = 200 * T;
    for (int i = 0; i <= N-T; i++){
        int curSum = 0;
        for(int j = 0; j < T; j++){
            curSum += abs(arr[i + j] - H);
        }
        minSum = min(minSum, curSum);
    }

    cout<<minSum;

    return 0;
}