#include <iostream>
#include <cmath> // pow
#include <climits> // INT_MAX
using namespace std;

int n, m, minDiff = INT_MAX;
int x[20], y[20];
pair<int, int> point[20];

int dist(pair<int, int> point1, pair<int, int> point2){
    return pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2);
}

void choose(int cnt, int idx){
    if (cnt == m){
        int diff = 0;
        for(int i = 0; i < m ;i++){
            for (int j = i + 1; j < m; j++){
                diff = max(diff, dist(point[i], point[j]));
            }
        }
        minDiff = min(diff, minDiff);
        return;
    }
    for(int i = idx; i < n; i++){
        point[cnt] = {x[i], y[i]};
        choose(cnt + 1, i + 1);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    choose(0, 0);
    
    cout<<minDiff;

    return 0;
}
