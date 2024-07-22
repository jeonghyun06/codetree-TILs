#include <iostream>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    
    int N;
    cin>>N;
    int x = 0;
    int y = 0;
    int t = -1;
    char dir; 
    int k, dirI;
    int tot = 0;
    for(int i=0;i<N;i++){
        cin>>dir>>k;
        switch(dir){
            case 'N':
                dirI = 1;
                break;
            case 'S':
                dirI = 0;
                break;
            case 'E':
                dirI = 2;
                break;
            case 'W':
                dirI = 3;
                break;
        }
        for(int j=0;j<k;j++){
            x += dx[dirI];
            y += dy[dirI];
            tot++;
            if(x == 0 && y == 0){
                t = tot;
                break;
            }
        }
        if(t!= -1) break;
    }

    cout<<t;
    return 0;
}