#include <iostream>

using namespace std;

int n, jumpCnt = 20;
int num[10];

void jump(int pos, int cnt){
    if(pos >= n - 1){
        jumpCnt = min(cnt, jumpCnt);
        return;
    }
    for(int i = 1; i <= num[pos]; i++) {
        jump(pos + i, cnt + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    jump(0, 0);

    if(jumpCnt == 20) cout<< -1;
    else cout<<jumpCnt;

    return 0;
}
