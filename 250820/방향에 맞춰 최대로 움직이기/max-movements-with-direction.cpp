#include <iostream>
#include <vector>
using namespace std;

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

int n, maxCnt;
int num[4][4];
int move_dir[4][4];
vector<pair<int, int>> dir_possible[4][4];
int r, c;

void direction(int x, int y, int cnt){
    if(dir_possible[x][y].empty()){
        maxCnt = max(maxCnt, cnt);
        return;
    }
    for(int i = 0; i < (int)dir_possible[x][y].size(); i++){
        direction(dir_possible[x][y][i].first, dir_possible[x][y][i].second, cnt + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            int x = i, y = j;
            while(true){
                x += dx[move_dir[i][j]];
                y += dy[move_dir[i][j]];
                if(x < 0 || y < 0 || x >= n || y >= n) break;

                if(num[i][j]<num[x][y]) {
                    dir_possible[i][j].push_back({x, y});
                }
            }
        }
    }

    direction(r-1, c-1, 0);

    cout<<maxCnt;


    return 0;
}
