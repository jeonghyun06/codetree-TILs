#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[20][20];
int maxCoin, maxSum;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    for (int i = 0; i < N; i++){ // 겹치는 부분이 있으면 안됨 -> 틀린 이유
        for (int j = 0; j < N - 2; j++){
            for(int k=0;k<N;k++){
                for(int l=0;l<N-2;l++){
                    if ((i==k) && abs(j-l)<=2) continue;
                    int grid1 = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                    int grid2 = arr[k][l] + arr[k][l+1] + arr[k][l+2];

                    maxSum = max(maxSum, grid1+grid2);
                }
            }
        }
    }
    cout<<maxSum;
    return 0;
}