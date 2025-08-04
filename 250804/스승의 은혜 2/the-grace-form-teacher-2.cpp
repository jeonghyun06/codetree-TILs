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
        int curCnt = 1;
        for (int j = 0; j < N; j++){
            if (i==j) continue;
            if(curSum>B) break;
            curSum += P[j];
            curCnt++;
        }
        cnt = max(cnt, curSum>B?curCnt-1:curCnt);
    }

    cout<<cnt;
    return 0;
}