#include <iostream>
#include <vector>
using namespace std;

int dx[3][4] = { {2, 1, -1, -2},
                {0, 1, 0, -1},
                {-1, 1, -1, 1} };

int dy[3][4] = { {0, 0, 0, 0},
                {1, 0, -1, 0},
                {1, 1, -1, -1} };

int n, cntMax;
int grid[20][20];
int boom[20][20];
vector<pair<int, int>> bombPos;

void bomb(int b, int x, int y, int check) {
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[b][i];
        int cy = y + dy[b][i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) continue;
        boom[cx][cy] += check;
    }
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        cout << boom[i][j]<<' ';
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';
   
}

void backtracing(int cnt) {
    if (bombPos.size() == cnt) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (boom[i][j]) cnt++;
            }
        }
        cntMax = max(cnt, cntMax);
        return;
    }
    for(int i = cnt; i < bombPos.size(); i++){
        if (cnt == 0 && i > 0) break;
        boom[bombPos[i].first][bombPos[i].second]++;
        for (int k = 0; k < 3; k++) {
            bomb(k, bombPos[i].first, bombPos[i].second, 1);
            backtracing(cnt + 1);
            bomb(k, bombPos[i].first, bombPos[i].second, -1);
        }
        boom[bombPos[i].first][bombPos[i].second]--;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) bombPos.push_back({ i, j });
        }
    }
    backtracing(0);

    cout << cntMax;

    return 0;
}
