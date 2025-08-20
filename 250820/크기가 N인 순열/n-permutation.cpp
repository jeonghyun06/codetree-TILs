#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int visited[9];

void backtracking(int cnt){
    if(cnt == n){
        for(int i = 0; i < n; i++) {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        arr.push_back(i);
        visited[i]++;

        backtracking(cnt + 1);
        
        arr.pop_back();
        visited[i]--;
    }
}

int main() {
    cin >> n;

    backtracking(0);

    return 0;
}
