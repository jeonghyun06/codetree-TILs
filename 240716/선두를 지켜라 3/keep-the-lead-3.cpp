#include <iostream>
using namespace std;

int A[1000001];
int B[1000001];

int main() {
    int N, M;
    cin>>N>>M;

    int time = 0;
    int cur = 0;
    int v, t;
    while(N--){
        cin >> v >> t;
        for(int i=0;i<t;i++){
            A[++time] = cur + v;
        }
    }

    time = 0;
    cur = 0;
    while(M--){
        cin >> v >> t;
        for(int i=0;i<t;i++){
            B[++time] = cur + v;

        }
    } 

    int pride = 0;
    int cnt = 0;
    for(int i=1;i<=time;i++){
        if(A[i] > B[i]){
            if(pride != 1) cnt++;
            pride = 1;
        }
        else if(A[i] < B[i]) {
            if(pride != 2) cnt++;
            pride = 2;
        }
        else {
            if(pride != 0) cnt++;
            pride = 0;
        }
    }

    cout<< cnt;
    return 0;
}