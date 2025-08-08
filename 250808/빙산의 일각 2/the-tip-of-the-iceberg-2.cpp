#include <iostream>

using namespace std;

int n, maxi;
int h[100];
int maxCnt;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        maxi = max(maxi, h[i]);
    }

    for(int i = 1; i < maxi; i++){
        int cnt = h[0]>i ? 1 : 0;
        for(int j = 1; j<n;j++){
            if(h[j]>i && h[j-1]<=i) cnt++;
        }
        maxCnt = max(maxCnt, cnt);
    }

    cout<<maxCnt;
    return 0;
}