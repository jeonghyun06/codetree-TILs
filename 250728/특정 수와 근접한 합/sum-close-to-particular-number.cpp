#include <iostream>
#include <cmath>
using namespace std;

int N, S;
int arr[100];
int sum;
int minSum;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    minSum = sum;

    for (int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int curSum = sum-arr[i]-arr[j];
            if (abs(S-minSum) > abs(S-curSum)){
                minSum = curSum;
            }
        }
    }

    cout<<abs(minSum-S);
    return 0;
}