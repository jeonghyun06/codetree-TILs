#include <iostream>
#include <algorithm>
using namespace std;

int N, M, cnt;
int A[100], B[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i]; // 원소 선택 (연속)

    for (int i = 0; i < M; i++) cin >> B[i]; // 아름다운 수열의 원소

    sort(B, B+M);

    for (int i = 0; i <= N-M; i++){
        bool check = true;
        int tmp[100];
        copy(A+i, A + i+M, tmp);
        sort(tmp,tmp+M);
        for (int j = 0; j < M; j++){
            if(tmp[j]!=B[j]) {check=false; break;}
        }
        if (check) cnt++;
    }
    cout<<cnt;
    return 0;
}