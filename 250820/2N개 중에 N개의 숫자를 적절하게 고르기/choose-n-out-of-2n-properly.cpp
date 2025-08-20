#include <iostream>

using namespace std;

int n, sum, minDiff = 10000;
int num[20];

void choose(int cnt, int curSum, int idx){
    if(cnt == n){
        minDiff = min(minDiff, abs(sum - 2 * curSum));
        return;
    }
    for(;idx < 2 * n; idx++){
        choose(cnt + 1, curSum + num[idx], idx + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        sum += num[i];
    }

    choose(0, 0, 0);

    cout<<minDiff;

    return 0;
}
