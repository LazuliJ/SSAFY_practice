#include <iostream>

using namespace std;

// 백준 1094번 막대기

int X;
int cnt = 0;

void input() {
    cin >> X;
}

int main() {
    input();
    for (int i = 64; i >= 1; i/=2) {
        if (X>=i) {
            X-=i;
            cnt++;
        }
    }
    cout << cnt;
}
