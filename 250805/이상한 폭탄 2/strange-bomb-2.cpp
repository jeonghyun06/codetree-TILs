#include <iostream>

using namespace std;

int N, K, boom = -1;
int num[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for(int i = 0; i + K < N && i < N; i++){
        for(int j = i + 1; j <= i + K && j < N; j++){
            if (num[j]==num[i]) {
                boom = max(boom, num[i]);
                break;
            }
        }
    }    

    cout<<boom;

    return 0;
}