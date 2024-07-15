#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main() {
    float d;
    cin>>d;

    int n = (int) d;
    d = d - n;

    string bin;
    int i=7;
    while(i--){
        if(n >= pow(2, i)){
            bin += '1';
            n -= pow(2,i);
        }
        else{
            bin += '0';
        }
    }
    bin = to_string(stoi(bin));

    bin += '.';

    i = 4;
    while(i--){
        n = d * 2;
        bin += (char)(n + 48); 
        d = d * 2 - n;
    }

    cout<<bin;
    return 0;
}