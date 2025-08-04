#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D, S, maxCnt;
int p[1000], m[1000], t[1000];
pair<int, int> sick[50];

bool twice( vector<pair<int, int>> vec, int k){
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].first==k) return true;
    }
    return false;
}

int main() {
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++) {
        cin >> p[i] >> m[i] >> t[i]; // 누가 어떤치즈 언제 먹었는지
    }

    for (int i = 0; i < S; i++) {
        cin >> sick[i].first>> sick[i].second; // 누가 언제 아팠는지
    }
    
    for (int i = 1; i <= M; i++){
        vector<pair<int, int>> eat;
        for(int j = 0; j < D; j++){
            if(m[j]==i && !twice(eat, p[j])) eat.push_back({p[j], t[j]});
        }

        int check = 0;
        for(int j = 0; j < S; j++){ // 아픈 사례
            for(int k = 0; k < eat.size(); k++){ //먹은 애들
                if(sick[j].first==eat[k].first && sick[j].second > eat[k].second) {
                    check++;
                    break;
                }
            }
        }

        if(S == check){
            maxCnt = max((int)eat.size(), maxCnt);
        }
    }

    cout<<maxCnt;
    return 0;
}