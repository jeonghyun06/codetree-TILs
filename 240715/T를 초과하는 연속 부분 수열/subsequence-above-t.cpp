#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin>>n>>t;

    int cnt = 0;
    int maxCnt = 0;
    bool c = false;
    int elem;
    while(n--){
        cin>>elem;
        if(c == true && elem > t){
            cnt++;
            maxCnt = max(cnt, maxCnt);
        }
        else if(elem > t){
            cnt = 1;
            maxCnt = max(cnt, maxCnt);
            c = true;
        }
        else{
            cnt = 0;
            c = false;
        }
    }

    cout<<maxCnt;
    return 0;
}