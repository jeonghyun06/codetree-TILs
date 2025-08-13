#include <iostream>
#include <vector>
using namespace std;

int dx[3][5] = { {2, 1, -1, -2, 0},
                {0, 1, 0, -1, 0},
                {-1, 1, -1, 1, 0} };

int dy[3][5] = { {0, 0, 0, 0, 0},
                {1, 0, -1, 0, 0},
                {1, 1, -1, -1, 0} };

int n, cntMax;
int grid[20][20];
int boom[20][20];
vector<pair<int, int>> bombPos;
vector<int> bombNum;

void bomb(int b, int x, int y, int check) {
    for (int i = 0; i < 5; i++) {
        int cx = x + dx[b][i];
        int cy = y + dy[b][i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) continue;
        boom[cx][cy] += check;
    }
}

void calc(int check) {
    for (int i = 0; i < bombNum.size(); i++) {
        bomb(bombNum[i], bombPos[i].first, bombPos[i].second, check);
    }
}

void backtracing(int cnt) {
    if (bombPos.size() == cnt) {
        calc(1);    //매번 배열을 바꾸지 않고 모든 조합을 결정하고 한 번만 계산
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (boom[i][j]) cnt++;
            }
        }
        cntMax = max(cnt, cntMax);
        calc(-1);
        return;
    }
    for(int i = 0; i < 3; i++){
        bombNum.push_back(i);
        backtracing(cnt + 1);
        bombNum.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
