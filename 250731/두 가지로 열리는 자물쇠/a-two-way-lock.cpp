#include <iostream>
#include <cmath>
using namespace std;

int N;
int a[3];
int b[3];
int cnt[3];

int main() {
    cin >> N;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    

    int ma = 5*5*5*2;
    for(int i=0;i<3;i++){
        // cnt[i] += max(N - 2 - arr[i], 0);
        // cnt[i] += max(arr[i] - 3, 0);
        int t1, t2;
        if (a[i]>b[i]){
            t1 = ((a[i] + 2) % N - (b[i] - 2 + N ) % N + N )% N + 1;
            t2 = ((a[i] - 2 + N) % N - (b[i] + 2) % N + N )% N + 1;
        }
        else{
            t1 = ((b[i] + 2) % N - (a[i] - 2 + N ) % N + N )% N + 1;
            t2 = ((b[i] - 2 + N) % N - (a[i] + 2) % N + N )% N + 1;
        }
        cnt[i] += t1<=5 ? t1: 0;
        cnt[i] += t2<=5 ? t2: 0;
        cnt[i] = min(cnt[i], 5);
    }

    cout<<ma - cnt[0]*cnt[1]*cnt[2];
    return 0;
}