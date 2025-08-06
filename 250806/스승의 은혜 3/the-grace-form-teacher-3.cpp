#include <iostream>
#include <algorithm>
using namespace std;

int N, B;
int P[1000];
int S[1000];
pair<int, int> price[1000];

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i] >> S[i];
        price[i].first= P[i] + S[i];
        price[i].second = P[i]/2 + S[i];
    }

    sort(price, price + N);

    int maxCnt = 0;
    int sum = 0;
    for(int j = 0; j < N; j++){
        if(sum + price[j].first > B){
            if(price[j].second + sum <= B) {
                maxCnt++;
                break;
            }
        }
        else{
            sum += price[j].first;
            maxCnt++;
        }
    }


    cout<<maxCnt;
    return 0;
}