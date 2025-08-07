#include <iostream>

using namespace std;

int N, C, G, H, maxWork;
int Ta[1000], Tb[1000];
int Tcnt[1001];

int main() {
    cin >> N >> C >> G >> H;

    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
        for(int j = 0; j < Ta[i]; j++){
            Tcnt[j] += C;
        }
        for(int j = Ta[i]; j <= Tb[i]; j++){
            Tcnt[j] += G;
        }
        for(int j = Tb[i] + 1; j <= 1000; j++){
            Tcnt[j] += H;
        }
    }

    for(int i = 0; i <= 1000; i++){
        maxWork = max(maxWork, Tcnt[i]);
    }

    cout<<maxWork;

    return 0;
}