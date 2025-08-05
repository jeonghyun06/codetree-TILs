#include <iostream>

using namespace std;

int K, n, cnt;
int arr[10][20];

int main() {
    cin >> K >> n;

    for (int i = 0; i < K; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (i == j) continue;
            int check = 1;
            for(int k = 0; k < K; k++){
                for(int l = 0; l < n; l++){
                    if(arr[k][l]==i) break;
                    if(arr[k][l]==j) {
                        check = 0;
                        break;
                    }
                }
            }
            cnt += check;
        }
    }

    cout<<cnt;
    return 0;
}