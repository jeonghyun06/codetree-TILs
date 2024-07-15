#include <iostream>
#include <string>
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
    for(int i=idxS; i<curS.length();i++){
        if(c[idxC] == curS[i]){
            back(i + 1, idxC+1, (nxt+1)%2);
        }
    }
}

int main() {
    cin >> c >> s[0] >> s[1];

    back(0,0,0);
    back(0,0,1);
    cout<<cnt;
    return 0;
}