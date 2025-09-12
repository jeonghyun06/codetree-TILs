#include <iostream>
#include <queue>
using namespace std;

int N, minCnt;
queue<pair<int, int>> q;
int visited[1000001];

void bfs(){
    while(!q.empty()){
        int x = q.front().second;
        int cnt = q.front().first;
        q.pop();
        
        if(x==1) {
            minCnt = cnt;
            break;
        }
        if(!visited[x+1]){
            q.push({cnt + 1, x + 1});
            visited[x + 1]++;
        }
        if(!visited[x-1]){
            q.push({cnt + 1, x - 1});
            visited[x - 1]++;
        }
        if(x%2==0 && !visited[x/2]) {
            q.push({cnt + 1, x/2});
            visited[x / 2]++;
        }

        if(x%3==0 && !visited[x/3]) {
            q.push({cnt + 1, x/3});
            visited[x / 3]++;
        }
    }
}

int main() {
    cin >> N;
    q.push({0, N});
    bfs();
    cout << minCnt;
    return 0;
}
