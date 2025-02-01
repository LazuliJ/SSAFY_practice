#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// 백준 2583번 영역 구하기
// BFS

using namespace std;

int N, M, K;
int MAP[101][101] = { 0, };
vector<int> ans;

void input() {
    cin >> M >> N >> K;
    for (int k = 0; k < K; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                MAP[y][x] = 1;
            }
        }
    }
}

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int BFS(int x, int y) {
    int ans = 1;
    deque<int> dq;

    MAP[y][x] = 2;
    dq.push_back(y);
    dq.push_back(x);

    while (!dq.empty()) {
        int yy = dq.front(); dq.pop_front();
        int xx = dq.front(); dq.pop_front();

        for (int dir = 0; dir < 4; dir++) {
            int ny = yy + dy[dir];
            int nx = xx + dx[dir];
            if (ny < 0 or nx < 0 or ny >= M or nx >= N) continue;
            if (MAP[ny][nx] != 0) continue;
            MAP[ny][nx] = 2;
            ans++;
            dq.push_back(ny);
            dq.push_back(nx);
        }
    }
    return ans;

}

int main() {
    input();
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (MAP[m][n] == 0) ans.push_back(BFS(n, m));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
