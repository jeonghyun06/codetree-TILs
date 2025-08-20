#include <iostream>
#include <climits>
using namespace std;

int n, minSum = INT_MAX;
int A[10][10];
int visited[10];

void cal(int cnt, int sum,int before){
    if(cnt==n){
        minSum = min(minSum, sum + A[before][0]);
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
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

    cal(0, 0, 0);
    cout<<minSum;

    return 0;
}
