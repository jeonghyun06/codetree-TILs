#include <iostream>

using namespace std;

int n;
int rect[1001];

int main() {
    cin >> n;

    rect[1] = 1;
    rect[2] = 2;

    for(int i = 3; i <= n; i++){
        rect[i] = (rect[i - 1] + rect[i - 2])%10007;
    }

    cout<<rect[n];
    return 0;
}
