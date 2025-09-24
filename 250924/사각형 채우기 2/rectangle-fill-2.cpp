#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int fn[1001]{};

    fn[0] = 1;
    fn[1] = 1;

    for(int i = 2; i <= n; i++){
        fn[i] = (fn[i-1] + fn[i-2] * 2) % 10007;
    }

    cout<<fn[n];

    return 0;
}
