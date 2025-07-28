#include <iostream>

using namespace std;

int N, K, maxsum;
int x[100];
char c[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> c[i];
    }

    for (int i=0;i<N;i++){
        int cursum= 0;
        for(int j=0;j<N;j++){
            if (x[j] >= x[i] && x[j] <= x[i]+K) cursum += c[j]-'F';
        }
        maxsum = max(maxsum, cursum);
    }
    cout<<maxsum;
    return 0;
}