#include <iostream>
#include <algorithm>
using namespace std;

int ability[6];
int abilitySum;
int minDiff = 2000000;

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
        abilitySum += ability[i];
    }

    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=0;k<6;k++){
                for(int l = k + 1; l < 6; l++){
                    if (i==k || j==k || j==l || i==k) continue;
                    int team1 = ability[i]+ability[j];
                    int team2 = ability[k]+ability[l];
                    int tmpMax = max({team1, team2, abilitySum - team1-team2});
                    int tmpMin = min({team1, team2, abilitySum - team1-team2});
                    minDiff = min(minDiff, tmpMax-tmpMin);
                }
            }
        }
    }

    cout<<minDiff;
    return 0;
}