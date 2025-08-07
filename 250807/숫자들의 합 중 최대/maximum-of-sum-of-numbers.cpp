#include <iostream>
#include <string>
using namespace std;

int X, Y;
int maxSum, cnt;

int main() {
    cin >> X >> Y;

    for(int i = X; i <= Y;i++ ){
        string number = to_string(i);
        cnt=0;
        for(int j = 0; j<number.length();j++){
            cnt += number[j] - '0';
        }
        maxSum = max(maxSum, cnt);
    }

    cout<<maxSum;

    return 0;
}