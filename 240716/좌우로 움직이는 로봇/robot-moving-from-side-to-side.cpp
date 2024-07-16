#include <iostream>
using namespace std;

int A[1000001];
int B[1000001];

int main() {
    int n, m;
    cin>>n>>m;

    int t, time = 0;
    char d;
    int cur = 0;
    
    while(n--){
        cin>>t>>d;
        if(d=='L'){
            for(int i=0;i<t;i++){
                A[++time] = --cur;
            }
        }
        else{
            for(int i=0;i<t;i++){
                A[++time] = ++cur;
            }
        }
    }
    int lastA=time;

    time = 0;
    cur = 0;
    while(m--){
        cin>>t>>d;
        if(d=='L'){
            for(int i=0;i<t;i++){
                B[++time] = --cur;
            }
        }
        else{
            for(int i=0;i<t;i++){
                B[++time] = ++cur;
            }
        }
    }
    int lastB = time;

    time = 0;
    int cnt=0;
    bool bef = true; // 이전에 같은 위치에 있는지 확인. 같은 위치면 1
    for(int i=0;i<max(lastA,lastB);i++){
        int curA = A[i];
        int curB = B[i];
        if(lastA<=i){
            curA = A[lastA];
        }
        if(lastB<=i){
            curB = B[lastB];
        }
        if(curB == curA){
            if(!bef){
                cnt++;
                bef = true;
            }
        }
        else{
            bef = false;
        }
    }
    cout<<cnt;
    return 0;
}