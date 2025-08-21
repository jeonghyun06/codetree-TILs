#include <iostream>
using namespace std;

int N, M;
int vertex[1001][1001];
int visited[1001];
int node[1001];

void dfs(int curNode){
    for(int i = 1 ; i <= N; i++){
        if(!visited[i] && vertex[curNode][i]){
            visited[i]++;
            dfs(i);
        }
    }
}

int main() {
    int x, y;

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        vertex[x][y] = 1;
        vertex[y][x] = 1;
    }

    dfs(1);

    int cnt = 0;
    for(int i = 2; i <= N; i++){
        if(visited[i]) cnt++;
    }
    cout<<cnt;

    return 0;
}