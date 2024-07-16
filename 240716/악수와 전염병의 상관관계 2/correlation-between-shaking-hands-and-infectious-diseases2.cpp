#include <iostream>
#include <queue>
using namespace std;

int virus[101][2];
priority_queue<pair<int,pair<int, int>>> shake;

int main() {
    // N명의 개발자
    // T번의 총 악수
    // 최초 감염자 P
    // 감염 후 K번 동안 전염병을 옮김.
    int N, K, P, T;
    cin>>N>>K>>P>>T;
    virus[P][0] = 1;

    int t, x, y;
    for(int i=0;i<T;i++) {
        cin>>t>>x>>y;
        shake.push({-t, {x, y}});
    }

    for(int i=0;i<T;i++){
        x = shake.top().second.first;
        y = shake.top().second.second;
        if(virus[x][0]==1 && virus[x][1]<K){ // 감염이 된 상태 + 전염가능 상태
            virus[x][1]++;
            if(virus[y][0]==0){
                virus[y][0] = 1;
            }
            else{
                virus[y][1]++;
            }
        }
        else if(virus[y][0]==1 && virus[y][1]<K){
            virus[y][1]++;
            virus[x][0] = 1;
        }
        shake.pop();
    }
    
    for(int i=1;i<=N;i++){
        cout<<virus[i][0];
    }
    return 0;
}