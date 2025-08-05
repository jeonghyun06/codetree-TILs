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

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                bool check = true;
                for (int m = 1; m < n; m++){
                    if (m==i || m==j || m==k) continue;
                    if (line[m-1].second > line[m].first) continue;
                    check = false;
                    break;
                }
                cnt += check ? 1 : 0;
            }
        }
    }

    cout<<cnt;

    return 0;
}