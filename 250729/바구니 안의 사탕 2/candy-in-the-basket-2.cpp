#include <iostream>

using namespace std;

int N, K, cp, bp, maxSum = 0;
int candy[101];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> cp >> bp;
        candy[bp] += cp;
    }

    for(int c = K + 1; c < 101-K ; c++){
        int curSum = 0;
        for(int i = c-K; i <= c + K; i++){
            curSum += candy[i];
        }
        maxSum = max(maxSum, curSum);
    }

    // 2k+1>=100 -> 전체합
    if (2*K + 1 >=100){
        int curSum = 0;
        for(int i=1;i<101;i++){
            curSum += candy[i];
        }
        maxSum = max(maxSum, curSum);
    }

    cout<<maxSum;
    return 0;
}