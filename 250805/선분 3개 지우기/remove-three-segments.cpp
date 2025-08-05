#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt;
pair<int, int> line[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
    }
    sort(line, line + n);

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                bool cc = true;
                int check[101]{};
                for (int m = 0; m < n; m++){
                    if (m==i || m==j || m==k) continue;
                    for(int l = line[m].first; l <= line[m].second; l++) check[l]++;
                }
                for(int m = 1; m < 101; m++){
                    if(check[m]>1) { cc = false; break;}
                }
                cnt += cc ? 1 : 0;
            }
        }
    }

    cout<<cnt;

    return 0;
}