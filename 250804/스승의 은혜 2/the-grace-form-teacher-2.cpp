#include <iostream>
#include <algorithm>
using namespace std;

int N, B, cnt;
int P[1000];

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P+N);

    for (int i = 0; i < N; i++){
        int curSum = P[i]/2;
        int curCnt = 0;
        for (int j = 0; j < N; j++){
            if (i==j) continue;
            curSum += P[j];
            curCnt++;
            if(curSum>B) break;
        }
        cnt = max(cnt, curCnt);
    }

    cout<<cnt;
    return 0;
}