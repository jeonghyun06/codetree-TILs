#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(b==0) return a;
    if(b>a) return GCD(b, a);
    int r = a%b;
    return GCD(b, r);
}

int main() {
    int n, m;
    cin>>n>>m;

    cout<<GCD(n, m);

    return 0;
}