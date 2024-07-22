#include <iostream>
using namespace std;

bool func(int n){
    return n%2==0 && ((n/10)+(n%10))%5==0;
}

int main() {
    int n;
    cin>>n;

    if(func(n)) cout<<"Yes";
    else cout<<"No";
    return 0;
}