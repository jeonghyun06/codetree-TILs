#include <iostream>

using namespace std;

int minSub = 3000000;
int sum;
int abilities[6];

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
        sum += abilities[i];
    }

    for(int i=0;i<6;i++){
        for(int j=i+1; j<6;j++){
            for(int k=j+1; k < 6; k++){
                int sumA = abilities[i] + abilities[j] + abilities[k];
                int sumB = sum - sumA;
                minSub = min(abs(sumA-sumB), minSub);
            }
        }
    }
    cout<<minSub;

    return 0;
}