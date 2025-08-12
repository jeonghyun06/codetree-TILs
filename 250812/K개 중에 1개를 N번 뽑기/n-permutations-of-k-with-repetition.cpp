#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> selected_nums;

void printArr(){
    for(int num : selected_nums){
        cout<<num<<' ';
    }
    cout<<'\n';
}

void backtracking(int n){
    if(n==N) {
        printArr();
        return;
    };
    for(int i = 1; i<=K;i++){
        selected_nums.push_back(i);
        backtracking(n + 1);
        selected_nums.pop_back();
    }

}

int main() {
    cin >> K >> N;

    backtracking(0);

    return 0;
}
