#include <iostream>
#include <vector>
using namespace std;

int N;
int perm[9];
int visited[9];

void backtracking(int cnt) {
    if(cnt == N){
        for(int i = 0; i < N; i++){
            cout<<perm[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = N; i > 0; i--){
        if(visited[i]) continue;

        perm[cnt] = i;
        visited[i]++;

        backtracking(cnt + 1);

        visited[i]--;
    }
}

int main() {
    cin >> N;

    backtracking(0);
    return 0;
}
