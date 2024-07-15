#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[2];
string c;
int cnt=0;

void back(int idxS,int idxC, int nxt){
    if(idxC==c.length()){
        cnt++;
        return;
    }
    string curS = s[nxt];
    int tmp = find(curS.begin() + idxS, curS.end(), c[idxC]) - curS.begin();
    while(tmp!=curS.length()){
        back(tmp + 1, idxC + 1, (nxt+1)%2);
        tmp = find(curS.begin() + tmp + 1, curS.end(), c[idxC]) - curS.begin();
    }
}

int main() {
    cin >> c >> s[0] >> s[1];

    back(0,0,0);
    back(0,0,1);
    cout<<cnt;
    return 0;
}