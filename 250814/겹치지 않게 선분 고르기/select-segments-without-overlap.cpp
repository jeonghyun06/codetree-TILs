#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, maxCnt;
vector<pair<int, int>> lines;
vector<int> selected_lines;

void backtracking(int x,int last, int cnt) {
    maxCnt = max(maxCnt, cnt);
    for (int i = x; i < n; i++) {
        if (last < lines[i].first) {
            selected_lines.push_back(i);
            backtracking(i+1, lines[i].second, cnt + 1);
            selected_lines.pop_back();
        }
    }
}

int main() {
    cin >> n;
    lines.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());

    backtracking(0,-1, 0);
    cout << maxCnt;

    return 0;
}