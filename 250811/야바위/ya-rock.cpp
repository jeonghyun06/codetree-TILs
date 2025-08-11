#include <iostream>

using namespace std;

int N, maxCnt;
int a[100], b[100], c[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i <= 3; i++){
        bool stone[4] = {0,};
        stone[i] = true;
        int cnt = 0;
        for(int j = 0; j < N; j++){
            bool tmp = stone[a[j]];
            stone[a[j]] = stone[b[j]];
            stone[b[j]] = tmp;
            if(stone[c[j]]) cnt++;
        }
        maxCnt = max(maxCnt, cnt);
    }

    cout<<maxCnt;

    return 0;
}