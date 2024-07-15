#include <iostream>
using namespace std;

int main() {
    int N;
    cin>>N;

    int maxCnt=1;
    int cnt=1;
    int n, before;

    cin>>n;
    before = n;
    N--;

    while(N--){
        cin >> n;
        if(n>before){
            cnt++;
            maxCnt = max(cnt, maxCnt);
        }
        else{
            cnt = 1;
        }
        before = n;
    }

    cout<<maxCnt;
    return 0;
}