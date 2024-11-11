#include <iostream>
#include <queue>
#include <algorithm>

// 백준 1926번 그림
/*
BFS를 이용하면 따로 떨어진 특정 덩어리들의 개수와 크기를 쉽게 알 수 있다.
*/

using namespace std;

/***************************/
int cnt = 0, ans = 0;
int n, m;
int MAP[501][501] = { 0, };
/***************************/

// input
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
}

// 방향배열
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

// BFS
int BFS(int y, int x) {
	queue<int> q;
	int pic_size = 1;
	MAP[y][x] = 0;
	cnt++;
	q.push(y); q.push(x);
	while (!q.empty()) {
		int yy = q.front(); q.pop();
		int xx = q.front(); q.pop();

		for (int i = 0; i < 4; i++) { 
			int ny = yy + dy[i];
			int nx = xx + dx[i];
		
			if (ny < 0 or nx < 0 or ny >= n or nx >= m) continue;
			if (MAP[ny][nx] == 0) continue;

			MAP[ny][nx] = 0;
			q.push(ny);
			q.push(nx);
			pic_size++;
		}
	}
	return pic_size;
}

// main
int main() {
	input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 1) {
				ans = max(ans, BFS(i, j));
			}
		}
	}
	cout << cnt << endl;
	cout << ans;
}
