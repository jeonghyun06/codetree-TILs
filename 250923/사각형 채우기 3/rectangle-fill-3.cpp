#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int rect[1001]{};

    rect[0] = 1;
    rect[1] = 2;

    for(int i = 2; i <= n; i++){
        rect[i] = (rect[i-1] * 2 + rect[i-2]  * 3) % 1000000007;
        for(int j = i - 3; j >= 0; j--){
            rect[i] = (rect[i] + rect[j] * 2) % 1000000007;
        }
    }

    cout << rect[n];

    return 0;
}
