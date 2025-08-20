#include <iostream>

using namespace std;

int n, m, k, maxCnt;
int nums[12];
int selected[12];

void cal(int cnt){
    if(cnt==n){
        int curCnt=0;
        int horse[12]{};
        for(int i = 0; i < n; i++){
           horse[selected[i]] += nums[i];
           if(horse[selected[i]] >= m - 1){
                curCnt++;
                horse[selected[i]] = -10000;
           }
        }
        maxCnt = max(maxCnt, curCnt);
        return;
    }
    for(int i = 0; i < k; i++){
        selected[cnt] = i;
        cal(cnt + 1);
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cal(0);

    cout<<maxCnt;

    return 0;
}
