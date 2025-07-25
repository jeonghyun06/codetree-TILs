#include <iostream>
using namespace std;

int N;
int arr[20][20];
int maxCoin, maxSum;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - 2; j++){
            int curCoin = 0;
            for(int k = 0; k < 3;k++){
                if(arr[i][j+k]==1) curCoin++;
            }
            maxSum = max(maxSum, maxCoin + curCoin);
            maxCoin = max(maxCoin, curCoin);
        }
    }
    cout<<maxSum;
    return 0;
}