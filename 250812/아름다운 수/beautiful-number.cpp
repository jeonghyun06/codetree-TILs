#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<int> beutiful;

void backtracking(int x){
    if(x == n){
        cnt++;
        return;
    }
    for(int i = 1;i<=4;i++){
        if(x + i > n) continue;
        for(int j=0;j<i;j++){
            beutiful.push_back(i);
        }
        backtracking(x + i);
        for(int j=0;j<i;j++){
            beutiful.pop_back();
        }
    }

}

int main() {
    cin >> n;

    backtracking(0);
    cout<<cnt;

    return 0;
}
