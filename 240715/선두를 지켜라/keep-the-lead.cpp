#include <iostream>
using namespace std;

int A[1000000];
int B[1000000];

int main() {
    int N, M;
    cin>>N>>M;

    int v, t;

    int time=0;
    while(N--){
        cin>>v>>t;
        for(int i=0;i<t;i++){
            time++;
            A[time] = A[time-1] + v;
        }
    }

    time = 0;
    while(M--){
        cin>>v>>t;
        for(int i=0;i<t;i++){
            time++;
            B[time] = B[time-1] + v;
        }
    }

    int before = 0;
    int cnt = 0;
    for(int i=0;i<time;i++){
        if(A[i]>B[i] && before != 1 ){
            before = 1;
            cnt++;
        }
        else if(A[i]<B[i] && before != 2 ){
            before = 2;
            cnt++;
        }
        else if(A[i]==B[i]){
            before = 0;
        }
    }

    if(cnt==0) cout<<0;
    else cout<<cnt - 1;
    return 0;
}