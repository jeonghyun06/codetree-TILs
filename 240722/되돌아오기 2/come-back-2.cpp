#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1}; // u, r, d, l
int dy[4] = {-1, 0, 1, 0};
int main() {
    int dir = 0;
    string s;
    cin>>s;
    int t=0;

    int x = 0, y = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='F'){
            x += dx[dir];
            y += dy[dir];
        }
        else if(s[i]=='L'){
            dir = (dir-1) % 4;
        }
        else if(s[i]=='R'){
            dir = (dir+1) % 4;
        }
        t++;

        if(x==0 && y==0) break;
    }
    if(x==0 && y==0) cout<<t;
    else cout<<-1;
    return 0;
}