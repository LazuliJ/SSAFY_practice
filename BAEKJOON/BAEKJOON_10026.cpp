#include <iostream>
#include <queue>

// 백준 10026번 적록색약
/* 
BFS로 flood fill하면서 하되, 
미리 데이터를 처리하여 버전 2개를 만들어둔다.
*/

using namespace std;

/*******************/
int N;
char MAP[101][101]; // 정상인 시점의 MAP
int crs = 0;
char MAP_rg[101][101]; // 색약 시점의 MAP (R로 통일)
int crs_rg = 0;
/*******************/

// input
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch;
			cin >> ch;
			
			MAP[i][j] = ch;
			// 색약 시점 데이터
			if (ch == 'G') {
				MAP_rg[i][j] = 'R';
			}
			else {
				MAP_rg[i][j] = ch;
			}
		}
	}
}

// 방향배열
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

// Flood Fill
void BFS(int y, int x, int mode) {
	int cur_cr;
	queue<int> q;
	if (mode == 0) {
		cur_cr = MAP[y][x];
		crs++;
		MAP[y][x] = '.';
	}
	else {
		cur_cr = MAP_rg[y][x];
		crs_rg++;
		MAP_rg[y][x] = '.';
	}

	q.push(y);
	q.push(x);
	
	while (!q.empty()) {
		int yy = q.front(); q.pop();
		int xx = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny < 0 or nx < 0 or ny >= N or nx >= N) continue;
			if (mode == 0 and MAP[ny][nx] != cur_cr) continue;
			if (mode == 1 and MAP_rg[ny][nx] != cur_cr) continue;
			if (mode == 0) {
				MAP[ny][nx] = '.';
			}
			if (mode == 1) {
				MAP_rg[ny][nx] = '.';
			}
			q.push(ny);
			q.push(nx);
		}
	}
}

// main
int main() {
	input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] != '.') {
				BFS(i, j, 0);
			}
			if (MAP_rg[i][j] != '.') {
				BFS(i, j, 1);
			}
		}
	}
	cout << crs << " " << crs_rg;
}
