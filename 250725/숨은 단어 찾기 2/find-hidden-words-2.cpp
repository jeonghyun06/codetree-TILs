#include <iostream>
#include <string>
#define DIREX_NUM 9
using namespace std;

int N, M;
int dx[DIREX_NUM] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[DIREX_NUM] = {0, 0, 0, -1, 1, 1, -1, 1, -1};
string arr[50];
string lee = "LEE";
int cnt=0;

bool inRange(int x, int y, int direx){
    if (x<0 || y<0 || x+dx[direx] * 2 >= N || y + dy[direx] * 2>= M || x+dx[direx] * 2 < 0 || y + dy[direx] * 2 < 0) return 0;
    return 1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (arr[i][j]!= lee[0]) continue;
            for(int k=0;k<DIREX_NUM;k++){
                if(!inRange(i,j,k)) continue;
                int check = 1;
                int curx = i;
                int cury = j;
                while(true){
                    int x = curx + dx[k] * check;
                    int y = cury + dy[k] * check;
                    if(arr[x][y]==lee[check]) check++;
                    else break;
                    if(check==3) {
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cout<<cnt;

    return 0;
}