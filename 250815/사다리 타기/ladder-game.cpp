#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, minCnt = 11;
pair<int, int> a[15];
vector<int> lines;
int answer[12];

bool step(){
    int curResult[12];
    for(int i = 0; i <= n; i++){
        curResult[i] = i;
    }

    for(int i = 0; i < (int)lines.size(); i++){
        swap(curResult[a[lines[i]].second], curResult[a[lines[i]].second + 1]);
    }
    return equal(answer, answer+n, curResult);
}

void ladder(int cnt){
    if(cnt == m){
        if(step())
            minCnt = min((int)lines.size(), minCnt);
        return;
    }
    lines.push_back(cnt);
    ladder(cnt + 1);
    lines.pop_back();
    ladder(cnt + 1);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i <= n ; i++){
        answer[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a, a+m);
    for(int i = 0; i < m; i++){
        swap(answer[a[i].second], answer[a[i].second + 1]);
    }

    ladder(0);
    cout<<minCnt;
    return 0;
}
