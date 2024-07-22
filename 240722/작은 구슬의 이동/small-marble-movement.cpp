#include <iostream>
#define LEFT 2
#define RIGHT 1
#define UP 3
#define DOWN 0
using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main() {
    int n, t;
    int r, c;
    char d;

    cin>>n>>t;
    cin>>r>>c>>d;
    int directionInt;
    if(d=='L') directionInt = LEFT;
    else if(d=='R') directionInt = RIGHT;
    else if(d=='U') directionInt = UP;
    else if(d=='D') directionInt = DOWN;

    while(t--){
        if (c + dx[directionInt] > n || c + dx[directionInt] <= 0 ||
        r + dy[directionInt] <= 0 || r + dy[directionInt] > n){
            directionInt = 3 - directionInt;
        }
        else{
            c = c + dx[directionInt];
            r = r + dy[directionInt];
        }
    }

    cout<<r<<' '<<c;
    return 0;
}