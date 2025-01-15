#include <iostream>
#include <vector>
#include <algorithm>

// 백준 2240번 자두나무
/*
전략: 
자두나무
T초 동안 떨어지는 자두 / 최대 W번 움직인다.
위치는 중요하지 않음(횟수가 중요하다.)
움직이냐 / 움직이지 않냐로 나누어 기록하기
2차 배열에 기록한다.
		현재 위치, 열매 개수
움직인 횟수

*/

using namespace std;

int T, W;
vector<int> fruit_cur;
int max_fruit[1001][31][2] = {0,};

void input() {
    cin >> T >> W;
    for (int t = 0; t < T; t++) {
        int fr;
        cin >> fr;
        fruit_cur.push_back(fr);
    }
}

void DP() {
    for (int i = 1; i < T; i++) {
        for (int j = 0; j <= W; j++) {
            if (max_fruit[i-1][j][0] == 0) continue;
            if (max_fruit[i-1][j][0] == fruit_cur[i]) {
                max_fruit[i][j][0] = max_fruit[i-1][j][0];
                max_fruit[i][j][1] = max(max_fruit[i][j][1], max_fruit[i-1][j][1] + 1);
            }
            else {
                max_fruit[i][j][0] = max_fruit[i-1][j][0];
                max_fruit[i][j][1] = max(max_fruit[i][j][1], max_fruit[i-1][j][1]);

                if (j == W) continue;
                max_fruit[i][j+1][0] = fruit_cur[i];
                max_fruit[i][j+1][1] = max(max_fruit[i][j+1][1], max_fruit[i-1][j][1] + 1);
            }
        }
    }
}

int find_ans() {
    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, max_fruit[T-1][i][1]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    max_fruit[0][0][0] = 1;
    max_fruit[0][0][1] = 1;
    if (fruit_cur[0] != 1) {
        max_fruit[0][0][1] = 0;
        max_fruit[0][1][0] = fruit_cur[0];
        max_fruit[0][1][1] = 1; 
    }
    DP();
    cout << find_ans();
    
}
