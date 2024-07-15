#include <iostream>
using namespace std;

int main() {
    int N;
    cin>>N;

    int maxCnt=1;
    int cnt=1;
    int before;
    int n;
    
    cin>>n;
    before = n;
    N--;

    while(N--){
        cin>>n;
        if(before * n > 0){
            cnt++;
            maxCnt = max(cnt, maxCnt);
        }
        else{
            cnt = 1;
            before = n;
        }
    }

    cout<<maxCnt;
    return 0;
}