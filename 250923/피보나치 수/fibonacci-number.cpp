#include <iostream>

using namespace std;

int N;
int fibo[45];

int fibonacci(int n){
    if(fibo[n]) return fibo[n];

    return fibo[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    cin >> N;

    fibo[0] = fibo[1] = 1;

    fibonacci(N-1);
    cout<<fibo[N-1];

    return 0;
}
