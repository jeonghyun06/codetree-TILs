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
    

    int ma = pow(N-5,3)*2;
    for(int i=0;i<3;i++){
        // cout<<max(0,5-(abs(a[i]-b[i]) % N))<<" ";
        cnt[i] = max(0,5-(abs(a[i]-b[i]) % N));
    }

    cout<<ma - cnt[0]*cnt[1]*cnt[2];
    return 0;
}