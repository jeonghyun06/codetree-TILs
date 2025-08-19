#include <iostream>

using namespace std;

int K, N;
int arr[9];

void choose(int cnt, int beforeCnt){
    if(cnt==N){
        for(int i = 0; i < N; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i = 1; i <= K; i++) {
        if(arr[cnt-1]==i && beforeCnt == 2) continue;
        arr[cnt] = i;
        choose(cnt + 1, (arr[cnt-1]==i) ? beforeCnt + 1 : 1);
    }
}

int main() {
    // 1~K를 N번 고르는 경우의 수 -> 같은 숫자가 3번이상 나오는 경우 제외
    cin >> K >> N;

    choose(0, 0);

    return 0;
}
