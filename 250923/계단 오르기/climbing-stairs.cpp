#include <iostream>

using namespace std;

int n;
int step[1001];

int stair(int s){
    if(s < 0) return 0;
    if(step[s]) return step[s];
    return step[s] = (stair(s-2) + stair(s-3)) % 10007;
}

int main() {
    cin >> n;

    step[0] = 1;

    cout<< stair(n);

    return 0;
}