#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

int N, M, K;
int height[50][50];
int visited[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int bx, int by){
    for(int i = 0 ; i < 4; i++){
        int x = bx + dx[i];
        int y = by + dy[i];

        if(x < 0 || y < 0 || x >= N || y >= M) continue;
        if(!visited[x][y] && height[x][y] > K){
            visited[x][y]++;
            dfs(x, y);
        }
        
    }
}

int main() {
    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>height[i][j];
        }
    }
    
    
    int cnt, maxCnt = 0;
    int minK = 100;
    for(int k = 1; k < 100; k++){
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        // 안전구역 개수 구하기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visited[i][j] && height[i][j] > k){
                    K = k;
                    cnt++; 
                    visited[i][j]++;
                    dfs(i, j);
                }
            }
        }

        // 안전구역 최대인 지점의 높이와 개수 저장
        if(maxCnt < cnt){
            minK = k;
            maxCnt = cnt;
        }
    }

    if(maxCnt==0) minK = 1;
    cout<<minK<<' '<<maxCnt;

    return 0;
}