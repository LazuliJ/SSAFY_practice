// 백준 - SWEA10966 유사문제
// 17086번 아기 상어2 (실버2)
#include <iostream>
#include <queue>

using namespace std;

int N, M;
queue<int> q;
int MAP[50][50] = { 0, };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;

			if (num == 0) MAP[i][j] = -1;
			else {
				MAP[i][j] = 0;
				q.push(i);
				q.push(j);
			}
		}
	}
}

int ydir[8] = { 1, -1, 0, 0, 1, -1, 1, -1};
int xdir[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int ans = 0;

void flood_fill() {
	while (!q.empty()) {
		int y = q.front(); q.pop();
		int x = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + ydir[i];
			int nx = x + xdir[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= M)continue;
			if (MAP[ny][nx] != -1) continue;
			MAP[ny][nx] = MAP[y][x] + 1;
			if (ans < MAP[ny][nx]) ans = MAP[ny][nx];
			q.push(ny); q.push(nx);
		}
	}
}

int main() {
	input();
	flood_fill();
	cout << ans;
}
