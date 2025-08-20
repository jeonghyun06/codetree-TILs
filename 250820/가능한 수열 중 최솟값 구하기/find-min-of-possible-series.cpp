#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[80];
bool totalCheck = false;

bool test(int t){
    for(int i = 1; i <= t / 2; i++){
        bool check = true;
        for(int j = 0; j < i; j++){
            // cout<<arr[t - j - 1]<<' '<<arr[t- j - i - 1]<<'\n';
            if(arr[t - j - 1] != arr[t - j - i - 1]) { //가장 마지막을 포함하는 경우만 확인
                check = false;
                break;
            }
        }
        if(check) return true;
    }
    return false;
}

// t = 4
// arr[3]==arr[1]
// arr[2]==arr[0]

void cal(int cnt){
    if(totalCheck) return;
    if(cnt==n){
        for(int i = 0; i < n; i++){
            cout<<arr[i];
        }
        totalCheck = true;
        return;
    }
    for(int i = 4; i < 7; i++){
        arr[cnt] = i;
        // test(cnt + 1);
        if(test(cnt+1)) continue;
        cal(cnt + 1);
    }
}

int main() {
    cin >> n;
    arr[0] = 4;
    cal(1);    

    return 0;
}
