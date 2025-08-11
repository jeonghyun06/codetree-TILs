#include <iostream>
#include <set>
using namespace std;

int n;
int x[20], y[20];
set<int> xCnt;
set<int> yCnt;
bool result = false;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        xCnt.insert(x[i]);
        yCnt.insert(y[i]);
    }
    
    // x축 평행 0
    if(xCnt.size()<=3 || yCnt.size() <= 3){
        result = true;
    }

    // x축 평행 1
    for(int i = 0; i < n; i++){
        yCnt.clear();
        for(int j = 0; j<n;j++){
            if(x[i]==x[j]) continue;
            yCnt.insert(y[j]);
        }
        if(yCnt.size()<=2) result = true;
    }

    // x축 평행 2
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j<n;j++){
            yCnt.clear();
            for(int k = 0; k < n; k++){
                if(x[k] == x[i] || x[k] == x[j]) continue;
                yCnt.insert(y[k]);
            }
            if(yCnt.size() <= 1) result =true;
        }
    }

    cout<<result;
    return 0;
}