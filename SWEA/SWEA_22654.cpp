// SWEA 22654. 차윤이의 RC카

#include <iostream>
#include <string>

using namespace std;

int T, N;
char MAP[5][5];
int sy, sx, ey, ex;

int Q;

char commands[5][51];

void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 51; j++) {
			commands[i][j] = '\0';
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'X') {
				sy = i;
				sx = j;
			}
			else if (MAP[i][j] == 'Y') {
				ey = i;
				ex = j;
			}
		}
	}
	
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int C;
		cin >> C;
		for (int j = 0; j < C; j++) {
			cin >> commands[i][j];
		}
	}
}

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void move(int t) {
	int ans[5] = { 0, };
	for (int i = 0; i < Q; i++) {
		int n = 0;
		int dir = 0;
		int x = sx;
		int y = sy;
		while (commands[i][n] != '\0') {
			if (commands[i][n] == 'R') {
				dir = (dir + 1) % 4;
			}
			else if (commands[i][n] == 'L') {
				dir = (dir + 3) % 4;
			}
			else if (commands[i][n] == 'A') {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (ny < 0 or nx < 0 or ny >= N or nx >= N) {
					n++;
					continue;
				}
				if (MAP[ny][nx] == 'T') {
					n++;
					continue;
				}
				x = nx;
				y = ny;
			}
			n++;
		}
		if (x == ex and y == ey) ans[i] = 1;
	}
	cout << "#" << t;
	for (int i = 0; i < Q; i++) {
		cout << " " << ans[i];
	}
	cout << "\n";
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		move(t);
	}
}
