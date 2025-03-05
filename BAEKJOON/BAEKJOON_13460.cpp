#include <iostream>
#include <vector>

using namespace std;

// 백준 13460번 구슬 탈출 2
// 시뮬레이션, DFS

int N, M;
int ans = 11;
char MAP[10][10];

int pos[4] = { 0, }; // initial_position

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'R') {
				pos[0] = i;
				pos[1] = j;
				MAP[i][j] = '.';
			}
			else if (MAP[i][j] == 'B') {
				pos[2] = i;
				pos[3] = j;
				MAP[i][j] = '.';
			}
		}
	}
}

// 0 = 상 1 = 하 2 = 좌 3 = 우

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

vector<int> move(int y, int x, int dir) {
	int oy = y; 
	int ox = x;
	vector<int> vec;

	while (true) {
		int next_y = oy + dy[dir];
		int next_x = ox + dx[dir];

		// 벽일때
		if (MAP[next_y][next_x] == '#') {
			vec.push_back(oy);
			vec.push_back(ox);
			break;
		}
		// 구멍으로 떨어졌을 때
		else if (MAP[next_y][next_x] == 'O') {
			vec.push_back(-1);
			vec.push_back(-1);
			break;
		}
		oy = next_y;
		ox = next_x;
	}

	return vec;
}

void DFS(int depth, int cur_ry, int cur_rx, int cur_by, int cur_bx) {
	if (depth == 10 or depth >= ans) {
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int first = 0;
		// 비교 (누가 먼저 움직여야 하는가?)
		if (dir == 0 and cur_by < cur_ry) first = 1;
		else if (dir == 1 and cur_by > cur_ry) first = 1;
		else if (dir == 2 and cur_bx < cur_rx) first = 1;
		else if (dir == 3 and cur_bx > cur_rx) first = 1;

		vector<int> next_r, next_b;

		// 실제로 움직이기
		if (first == 0) {
			next_r = move(cur_ry, cur_rx, dir);
			next_b = move(cur_by, cur_bx, dir);
			if (next_r[0] != -1 and next_r == next_b) {
				next_b[0] -= dy[dir];
				next_b[1] -= dx[dir];
			}
		}
		if (first == 1) {
			next_b = move(cur_by, cur_bx, dir);
			next_r = move(cur_ry, cur_rx, dir);
			if (next_r[0] != -1 and next_r == next_b) {
				next_r[0] -= dy[dir];
				next_r[1] -= dx[dir];
			}
		}
		if (next_b[0] == -1) continue;
		else if (next_r[0] == -1) {
			ans = depth + 1;
			continue;
		}
		DFS(depth + 1, next_r[0], next_r[1], next_b[0], next_b[1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	DFS(0, pos[0], pos[1], pos[2], pos[3]);

	if (ans != 11) cout << ans;
	else cout << -1;
}
