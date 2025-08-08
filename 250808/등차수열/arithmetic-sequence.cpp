#include <iostream>

using namespace std;

int n,maxCnt;
int maxi, mini = 100;
int a[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
    }

    for(int i = mini; i <= maxi; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if( a[j]-i == i-a[k]) cnt++;
            }
        }
        maxCnt = max(cnt, maxCnt);
    }

    cout<<maxCnt;
    return 0;
}