#include <iostream>

using namespace std;

int N;
int x[100];
int y[100];
int triangle;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                if(((x[i]==x[j]) || (x[j]==x[k]) || (x[i]==x[k])) && !(x[i]==x[j]==x[k])
                    && ((y[i]==y[j]) || (y[j]==y[k]) || (y[i]==y[k])) && !(y[i]==y[j]==y[k])){
                        int dx = max(max(x[i],x[j]), x[k]) - min(min(x[i],x[j]), x[k]);
                        int dy = max(max(y[i],y[j]), y[k]) - min(min(y[i],y[j]), y[k]);
                        triangle = max(triangle, dx * dy);
                    }
            }
        }
    }

    cout<<triangle;
    return 0;
}