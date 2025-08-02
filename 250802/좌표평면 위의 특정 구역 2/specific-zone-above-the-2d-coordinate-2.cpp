#include <iostream>

using namespace std;

int N;
int x[100], y[100];
int rectangle = 40000*40000;
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < N; i++){ // 뺼 점 선택
        int minX = 40000, minY = 40000, maxX = 0, maxY = 0;
        for(int j = 0; j < N; j++){ //각 상황별 직사각형 크기
            if (i == j) continue;
            minX = min(x[j], minX);
            minY = min(y[j], minY);
            maxX = max(x[j], maxX);
            maxY = max(y[j], maxY);
        }
        rectangle = min(rectangle, (maxX-minX) * (maxY-minY));
    }
    cout<<rectangle;
    return 0;
}