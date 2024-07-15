#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    char d;
    int t;

    int A[1000000];
    int B[1000000];
    
    int cur=0;
    int fir = -1;
    int timeA=0;
    for(int i = 0; i < N; i++){
        cin >> d >> t;
        if(d=='L'){
            for(int j=0;j<t;j++){
                A[timeA++] = --cur;
            }
        }
        else {
            for(int j=0;j<t;j++){
                A[timeA++] = ++cur;
            }
        }
    }

    cur = 0;
    int timeB = 0;
    for(int i = 0; i < M; i++){
        cin >> d >> t;
        if(d=='L'){
            for(int j=0;j<t;j++){
                B[timeB++] = --cur;
            }
        }
        else {
            for(int j=0;j<t;j++){
                B[timeB++] = ++cur;
            }
        }
    }

    for(int i=0;i<max(timeA, timeB);i++){
        if(A[i] == B[i]){
            fir = i + 1;
            break;
        }
    }
    cout<<fir;

    return 0;
}