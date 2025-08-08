#include <iostream>
#include <string>
using namespace std;

int X, Y, cnt;

int main() {
    cin >> X >> Y;

    for(int i = X; i <= Y; i++){
        string str = to_string(i);
        bool check = true;
        for(int j = 0; j < str.length()/2; j++){
            if(str[j] == str[str.length() - j - 1]) continue;
            check = false;
            break;
        }
        if(check) cnt++;
    }

    cout<<cnt;

    return 0;
}