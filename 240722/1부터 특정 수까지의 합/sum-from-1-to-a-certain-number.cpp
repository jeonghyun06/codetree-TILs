#include <iostream>
using namespace std;

int sum(int n){
    return (n + 1) * n / 20;
}

int main() {
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}