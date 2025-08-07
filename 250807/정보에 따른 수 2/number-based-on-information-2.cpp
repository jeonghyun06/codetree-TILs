#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, a, b, cnt;
char tmpC;
int tmpX;
vector<int> N;
vector<int> S;

int distance(vector<int> al, int x) {
    if (al.back() <= x)
        return x - al.back();
    else if(al.front() >= x)
        return al[0] - x;
    else{
        int S1 = lower_bound(al.begin(), al.end(), x) - al.begin();
        int S2 = S1 - 1;
        return min(al[S1] - x, x - al[S2]);
    }
}

int main() {
    cin >> T >> a >> b;

    for (int i = 0; i < T; i++) {
        cin >> tmpC >> tmpX;
        if (tmpC == 'N') N.push_back(tmpX);
        else S.push_back(tmpX);
    }

    sort(N.begin(), N.end());
    sort(S.begin(), S.end());

    for (int i = a; i <= b; i++) {
        int d1 = distance(S, i);
        int d2 = distance(N, i);

        if (d1 <= d2) cnt++;
    }

    cout << cnt;

    return 0;
}