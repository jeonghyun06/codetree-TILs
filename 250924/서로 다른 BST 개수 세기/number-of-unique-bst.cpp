#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int dp[20]{};

    dp[0] = 1;
    dp[1] = 1;
    // dp[2] = dp[1] * 2;
    // dp[3] = dp[2] * dp[0] * 2 + dp[1] * dp[1];
    // dp[4] = dp[3] * dp[0] * 2 + dp[2] * dp[1] * 2;
    // dp[5] = dp[4] * dp[0] * 2 + dp[3] * dp[1] * 2 + dp[2] * dp[2];
    // dp[6] = dp[5] * dp[0] * 2 + dp[4] * dp[1] * 2 + dp[3] * dp[2] * 2;

    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j >= 0; j--){
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    cout<<dp[n];

    return 0;
}
