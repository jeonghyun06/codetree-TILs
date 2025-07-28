#include <iostream>
#include <algorithm>
using namespace std;

int n,cnt;
int arr[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        float cursum=0;
        for(int j=i;j<n;j++){
            cursum+=arr[j];
            if(find(arr+i,arr+j+1,cursum/(j-i+1))<arr+j+1){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}