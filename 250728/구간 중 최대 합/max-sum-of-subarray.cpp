#include <iostream>

using namespace std;

int n, k, maxSum, curSum;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0;i<n-k;i++){
        curSum = 0;
        for (int j=0;j<k;j++){
            curSum += arr[i+j];
        }
        maxSum = max(maxSum, curSum);
    }

    cout<<maxSum;

    return 0;
}