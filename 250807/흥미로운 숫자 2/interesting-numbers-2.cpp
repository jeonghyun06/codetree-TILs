#include <iostream>
#include <string>
using namespace std;

int X, Y;
int cnt;

int main() {
    cin >> X >> Y;

    for(int i = X; i <= Y; i++){
        string number = to_string(i);
        int digit[10]{};
        
        for(int j = 0; j<number.length();j++){
            digit[number[j]-'0']++;
        }
        for(int j = 0; j < 10;j++){
            if(digit[j]==number.length( )- 1) cnt++;
        }
    }

    cout<<cnt;
    
    return 0;
}