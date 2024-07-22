#include <iostream>
using namespace std;

void square(int n){
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<k%9+1<<' ';
            k++;
        }
        cout<<"\n";
    }
}

int main() {
    int N;
    cin>>N;

    square(N);

    return 0;
}