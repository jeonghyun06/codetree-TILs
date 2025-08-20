#include <iostream>
#include <climits>
using namespace std;

int n, minSum = INT_MAX;
int A[10][10];
int visited[10];

void cal(int cnt, int sum, int before){
    if(cnt==n){
        if(A[before][0]==0) return;
        minSum = min(minSum, sum + A[before][0]);
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[i] || A[before][i]==0) continue;
        visited[i]++;
        cal(cnt + 1, sum + A[before][i], i);
        visited[i]--;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    
    visited[0]++;
    cal(1, 0, 0);
    cout<<minSum;

    return 0;
}
