#include <iostream>

using namespace std;

int A, B, C;
int maxSum;

int main() {
    cin >> A >> B >> C;

    // 개수 0 -> C/A
    for(int i = 0; i <= C/A; i++){
        int sum = i * A + ((C - i * A) / B) * B;
        maxSum = max(sum, maxSum);
    }

    cout<<maxSum;

    return 0;
}