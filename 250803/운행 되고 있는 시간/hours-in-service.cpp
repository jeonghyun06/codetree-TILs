#include <iostream>

using namespace std;

int N, maxTime;
int A[100], B[100];
int working[1001];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        for(int j = A[i]; j < B[i]; j++) working[j]++;
    }

    for(int i = 0; i < N; i++){
        int time = 0;
        
        for(int j = 0; j < 1000; j++){
            if (A[i]<=j && B[i]>j)
                if (working[j] - 1 > 0) time++;
                else continue;
            else if (working[j]) time++;
        }
        maxTime = max(maxTime, time);
    }

    cout<<maxTime;
    return 0;
}