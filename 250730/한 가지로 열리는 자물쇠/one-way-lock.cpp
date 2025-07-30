#include <iostream>

using namespace std;

int N;
int arr[3];

int main() {
    cin >> N;
    cin >> arr[0] >> arr[1] >> arr[2];

    // 계산
    int cnt[3]{};
    for(int i = 0; i < 3; i++){
        cnt[i] += max(N - 2 - arr[i], 0);
        cnt[i] += max(arr[i] - 3, 0);
    }

    cout << N*N*N - cnt[0] * cnt[1] * cnt[2];

    return 0;
}