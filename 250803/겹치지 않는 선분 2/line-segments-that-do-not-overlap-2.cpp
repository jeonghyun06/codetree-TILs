#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N;
set<int> crossPoint;
pair<int, int> point[100];

bool compare(pair<int, int> x1, pair<int, int> x2){
    return x1.first < x2.first;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> point[i].first >> point[i].second;
    }

    sort(point, point + N, compare);

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if (point[i].second < point[j].second) continue;
            crossPoint.insert(i);
            crossPoint.insert(j);
        }
    }

    cout<<N - crossPoint.size();
    return 0;
}