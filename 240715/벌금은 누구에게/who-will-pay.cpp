#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    int n;
    int answer = -1;
    cin>>N>>M>>K;
    int student[101]{};
    while(M--){
        cin>>n;
        student[n]++;
        if(answer == -1 && student[n]>=K){
            answer = n;
        }
    }
    cout<<answer;
    return 0;
}