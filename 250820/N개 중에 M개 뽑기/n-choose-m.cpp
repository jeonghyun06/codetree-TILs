#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void choose(int cnt){
    if(cnt==M){
        for(int i = 0; i < M ; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int i = arr.empty() ? 1 : arr.back() + 1;
    for(; i <= N; i++){
        arr.push_back(i);
        choose(cnt + 1);
        arr.pop_back();
    }
}

int main() {
    cin >> N >> M;

    choose(0);

    return 0;
}
