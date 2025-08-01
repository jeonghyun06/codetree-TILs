#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];
int sum;
int minDiff = 2000;

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if (i == k || j == k) continue;
                int teama = arr[i] + arr[j];
                int teamb = arr[k];
                int teamc = sum - teama - teamb;
                if (teama == teamb || teama == teamc || teamb == teamc) continue;
                int minSum = min({teama, teamb, teamc});
                int maxSum = max({teama, teamb, teamc});
                minDiff = min(maxSum - minSum, minDiff);
            }
        }
    }

    if (minDiff == 2000) cout << -1;
    else cout << minDiff;
    return 0;
}