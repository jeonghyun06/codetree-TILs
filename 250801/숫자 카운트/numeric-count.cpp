#include <iostream>
using namespace std;

//홈런 게임 -> 볼(c) 스트라이크(b)
int n, count;
string a[10];
int b[10], c[10];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            if (i==j) continue;
            for (int k = 1; k < 10; k++){
                if (i==k || j==k) continue;
                int check = 0;
                for(int l = 0; l < n; l++){
                    int ball = 0;
                    int strike = 0;
                    if(i == a[l][0]-'0') strike++;
                    else if(j==a[l][0]-'0' || k==a[l][0]-'0') ball++;
                    
                    if(j == a[l][1]-'0') strike++;
                    else if(i==a[l][1]-'0' || k==a[l][1]-'0') ball++;

                    if(k == a[l][2]-'0') strike++;
                    else if(i==a[l][2]-'0' || j==a[l][2]-'0') ball++;

                    if (strike != b[l] || ball != c[l]) break;
                    check++;
                }
                if (check == n) count++;
            }
        }
    }

    cout<<count;

    return 0;
}