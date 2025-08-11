#include <iostream>

using namespace std;

int n, minDiff = 10000;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        arr[i] *= 2;
        for(int j = 0; j < n; j++){
            if(i==j) continue;
            int tmp = arr[j];
            arr[j] = j>0 ? arr[j-1] : arr[j+1];
            int diff = 0;
            for(int k = 1; k < n; k++){
                diff += abs(arr[k] - arr[k-1]);
            }
            minDiff = min(minDiff, diff);
            arr[j] = tmp;
        }
        arr[i] /= 2;
    }

    cout<<minDiff;
    return 0;
}