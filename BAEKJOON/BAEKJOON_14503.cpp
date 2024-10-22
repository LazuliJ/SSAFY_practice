// 백준 14503번 로봇청소기
// 딱히 특기할만한 사항이 없는 시뮬레이션 유형 문제

#include <iostream>

using namespace std;

int N, M;
int MAP[50][50] = { 0, };
int cur_y, cur_x, cur_dir;
int cnt = 0; // 청소하는 칸(정답)
void input() {
	cin >> N >> M;
	cin >> cur_y >> cur_x >> cur_dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void move() {
	while(true) {
		if (MAP[cur_y][cur_x] == 0) {
			MAP[cur_y][cur_x] = 2;
			cnt++;
		}

		int flag = 0;
		for (int i = 1; i <= 4; i++) {
			int dir = cur_dir - i;
			if (dir < 0) {
				dir += 4;
			}

			int y = cur_y + dy[dir];
			int x = cur_x + dx[dir];
			if (y < 0 or x < 0 or y >= N or x >= M) continue;

			if (MAP[y][x] == 0) {
				flag = 1;
				cur_y = y; cur_x = x; cur_dir = dir;
				break;
			}
		}
		if (flag == 1) {
			continue;
		}
		else {
			int y = cur_y - dy[cur_dir];
			int x = cur_x - dx[cur_dir];
			if (y < 0 or x < 0 or y >= N or x >= M) {
				return;
			}
			if (MAP[y][x] == 1) {
				return;
			}
			else {
				cur_y = y;
				cur_x = x;
			}
		}
	}
}

int main() {
	input();
	move();
	cout << cnt << endl;
}
