#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string expression;
vector<int> alpha;
int maxRslt = INT_MIN;

void cal(int cnt){
    if(cnt==6){
        int rslt = alpha[expression[0]-'a'];
        for(int i=2;i<expression.length(); i += 2){
            if(expression[i-1]=='+'){
                rslt += alpha[expression[i]-'a'];
            }
            else if(expression[i-1]=='-'){
                rslt -= alpha[expression[i]-'a'];
            }
            else if(expression[i-1]=='*'){
                rslt *= alpha[expression[i]-'a'];
            }
        }
        maxRslt = max(rslt, maxRslt);
        return;
    }
    for(int i=1;i<=4;i++){
        alpha.push_back(i);
        cal(cnt + 1);
        alpha.pop_back();
    }
}

int main() {
    cin >> expression;

    cal(0);

    cout<<maxRslt;

    return 0;
}
