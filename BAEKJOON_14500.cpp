// 백준 14500번 테트로미노
#include <iostream>

using namespace std;

int N, M;
int MAP[500][500] = { 0, };
int tmp = 0, ans = 0;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}

int visited[500][500] = { 0, };

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { -1, 1, 0, 0 };

void DFS(int y, int x, int depth) {
	if (depth == 3) {
		if (ans < tmp) {
			ans = tmp;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
		if (visited[ny][nx] == 1) continue;

		tmp += MAP[ny][nx];
		visited[ny][nx] = 1;
		DFS(ny, nx, depth + 1);
		visited[ny][nx] = 0;
		tmp -= MAP[ny][nx];
	}
}

void others(int y, int x) {
	if (x + 1 < M and y + 1 < N and y - 1 >= 0) {
		tmp = MAP[y][x] + MAP[y][x + 1] + MAP[y + 1][x + 1] + MAP[y - 1][x + 1];
		if (tmp > ans) ans = tmp;
	}
	if (x - 1 >= 0 and y + 1 < N and y - 1 >= 0) {
		tmp = MAP[y][x] + MAP[y][x - 1] + MAP[y + 1][x - 1] + MAP[y - 1][x - 1];
		if (tmp > ans) ans = tmp;
	}
	if (y + 1 < N and x + 1 < M and x - 1 >= 0) {
		tmp = MAP[y][x] + MAP[y + 1][x] + MAP[y + 1][x + 1] + MAP[y + 1][x - 1];
		if (tmp > ans) ans = tmp;
	}
	if (y - 1 >= 0 and x + 1 < M and x - 1 >= 0) {
		tmp = MAP[y][x] + MAP[y - 1][x] + MAP[y - 1][x + 1] + MAP[y - 1][x - 1];
		if (tmp > ans) ans = tmp;
	}

	tmp = 0;
}

int main() {
	input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp += MAP[i][j];
			visited[i][j] = 1;
			DFS(i, j, 0);
			visited[i][j] = 0;
			tmp -= MAP[i][j];

			others(i, j);
		}
	}
	cout << ans;
}
