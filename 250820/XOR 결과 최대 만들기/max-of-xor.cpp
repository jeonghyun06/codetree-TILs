#include <iostream>
using namespace std;

int n, m, maxXor;
int A[20];
int selected[20];

void cal(int cnt, int x){
    if(cnt == m){
        int xorResult = A[selected[0]];
        for(int i = 1; i < m; i++){
            xorResult = xorResult ^ A[selected[i]]; 
        }
        maxXor = max(maxXor, xorResult);
    }
    for(; x < n; x++){
        selected[cnt] = x;
        cal(cnt + 1, x + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cal(0, 0);

    cout<<maxXor;

    return 0;
}