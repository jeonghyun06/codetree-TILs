#include <iostream>
using namespace std;

int main() {
    int N;
    cin>>N;

    int maxCnt=1;
    int before=-1;
    int cnt=1;
    int n;
    for(int i=0;i<N;i++){
        cin>>n;
        if(n==before){
            cnt++;
            maxCnt = max(maxCnt, cnt);
        }
        else{
            before = n;
            cnt=1;
        }
    }

    cout<<maxCnt;
    return 0;
}