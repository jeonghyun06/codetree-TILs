#include <iostream>

using namespace std;

int N, K, cp, bp, maxSum = 0;
int candy[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> cp >> bp;
        candy[bp] += cp;
    }

    for(int c = K; c < 100-K ; c++){
        int curSum = 0;
        for(int i = c-K; i <= c + K; i++){
            curSum += candy[i];
        }
        maxSum = max(maxSum, curSum);
    }

    cout<<maxSum;
    return 0;
}