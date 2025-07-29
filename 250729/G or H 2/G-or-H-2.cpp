#include <iostream>
#include <algorithm>
using namespace std;

int N,maxRange;
pair<int, char> pos[100];

int compare(pair<int, char> a, pair<int, char> b){
    return a.first<b.first;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    sort(pos, pos + N, compare);

    for(int i=0;i<N;i++){
        int cnt = (pos[i].second=='G') ? 1:-1;
        for(int j=i+1;j<N;j++){
            cnt += (pos[j].second=='G') ? 1:-1;
            if(cnt==0 || abs(cnt)==j-i+1){
                maxRange = max(maxRange, pos[j].first-pos[i].first);
            }
        }
    }

    cout<<maxRange;

    return 0;
}