// SWEA 22683번 나무 베기 
#include <iostream>
#include <algorithm>

using namespace std;

/*******************/
int T;
int N, K;
int st_y, st_x;
int ans = 100;
int MAP[10][10];
int visited[10][10];
/*******************/

// 초기화
void init() {
	ans = 100;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			MAP[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

// 입력
void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch;
			cin >> ch;
			if (ch == 'X') {
				st_y = i;
				st_x = j;
				MAP[i][j] = 0;
			}
			else if (ch == 'Y') {
				MAP[i][j] = 2;
			}
			else if (ch == 'G') {
				MAP[i][j] = 0;
			}
			else if (ch == 'T') {
				MAP[i][j] = 1;
			}
		}
	}
}

// 방향배열
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

// DFS 최단조작 찾기
void DFS(int y, int x, int dir, int t, int time) {
	if (MAP[y][x] == 2) {
		ans = min(ans, time);
		return;
	}
	for (int di = 0; di < 4; di++) {
		int ny = y + dy[di];
		int nx = x + dx[di];

		// 나무를 더이상 벨 수 없거나 이미 visit했거나 범위를 벗어나는 경우
		if (ny < 0 or nx < 0 or ny >= N or nx >= N) continue;
		if (visited[ny][nx] == 1) continue;
		if (MAP[ny][nx] == 1 and t == K) continue;

		// 현재 최솟값보다 더 많은 시간을 허비 
		// *핵심 조건* 최근 얻었던 최솟값을 반영함으로서 DFS도 시간 절약이 가능하다.
		if (time > ans) continue;

		// 진전 가능
		int _t = t;
		if (MAP[ny][nx] == 1) _t++;

		visited[ny][nx] = 1;
		// 반대 방향
		if (abs(di - dir) == 2) {
			DFS(ny, nx, di, _t, time + 3);
		}
		// 같은 방향
		else if (di == dir) {
			DFS(ny, nx, di, _t, time + 1);
		}
		// 좌/우회전
		else {
			DFS(ny, nx, di, _t, time + 2);
		}
		visited[ny][nx] = 0;
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		visited[st_y][st_x] = 1;
		DFS(st_y, st_x, 0, 0, 0);
		if (ans == 100) ans = -1; // 예외처리 (찾을 수 없음)
		cout << "#" << t << " " << ans << "\n";
	}
}
