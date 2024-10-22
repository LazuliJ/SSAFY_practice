// 17144번 미세먼지 안녕!
#include<iostream>

using namespace std;

int R, C, T;
int MAP[50][50] = { 0, };
int y_1, y_2;

void input() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
			if (i != 0 and MAP[i - 1][j] == -1 and MAP[i][j] == -1) {
				y_1 = i - 1;
				y_2 = i;
			}
		}
	}
}

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

int visited[50][50] = { 0, };

void flood() {
	// "동시에" 일어나므로 이후 반영
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == -1) continue;
			if (MAP[i][j] == 0) continue;
			int cnt = 0; // 확산된 방향
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 or nx < 0 or ny >= R or nx >= C) continue;
				if (MAP[ny][nx] == -1) continue;
				visited[ny][nx] += (MAP[i][j] / 5);
				cnt++;
			}
			MAP[i][j] -= ((MAP[i][j] / 5)*cnt);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			MAP[i][j] += visited[i][j];
		}
	}
}

void air() {
	int y = y_1; int x = 0;
	while (y > 0) {
		MAP[y][x] = MAP[y-1][x];
		y--;
	}
	y = 0;
	while (x < C-1) {
		MAP[y][x] = MAP[y][x + 1];
		x++;
	}
	x = C - 1;
	while (y < y_1 ) {
		MAP[y][x] = MAP[y+1][x];
		y++;
	}
	y = y_1;
	while (x > 0) {
		MAP[y][x] = MAP[y][x-1];
		x--;
	}
	MAP[y_1][1] = 0;
	MAP[y_1][0] = -1;

	y = y_2; x = 0;
	while (y < R-1) {
		MAP[y][x] = MAP[y + 1][x];
		y++;
	}
	y = R-1;
	while (x < C - 1) {
		MAP[y][x] = MAP[y][x + 1];
		x++;
	}
	x = C - 1;
	while (y > y_2) {
		MAP[y][x] = MAP[y - 1][x];
		y--;
	}
	y = y_2;
	while (x > 0) {
		MAP[y][x] = MAP[y][x - 1];
		x--;
	}
	MAP[y_2][1] = 0;
	MAP[y_2][0] = -1;
} 

int main() {
	input();
	for (int t = 1; t <= T; t++) {
		flood();
		air();
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == -1)continue;
			ans += MAP[i][j];
		}
	}
	cout << ans;
}
