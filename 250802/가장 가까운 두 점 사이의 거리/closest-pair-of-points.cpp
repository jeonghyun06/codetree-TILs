#include <iostream>
#include <cmath>
using namespace std;

int n;
int x[100], y[100];
int dist = 2000000;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            dist = min((int)pow(x[i] - x[j],2) + (int)pow(y[i] - y[j],2), dist);
        }
    }
    cout<<dist;
    return 0;
}