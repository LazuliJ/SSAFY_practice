// 백준 1189번 - 실버 1 (DFS 기본)
/*
1. N이 작음(5 이하) = 완탐일 가능성이 높다.
2. MAP형태로 주어진 목적지와 출발지
3. 다시 들르진 않음(visited)
= DFS를 시도해보자!!
*/

#include <iostream>
using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int MAP[5][5] = { 0, };
int visited[5][5] = { 0, };
int ans = 0;

int R, C, K;
// start = R-1 0 end = 0 C-1

void input() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char a;
			cin >> a;
			if (a == '.')MAP[i][j] = 0;
			if (a == 'T')MAP[i][j] = 1;
		}
	}
}

void DFS(int y, int x) {
	if (y == 0 and x == C - 1 and visited[y][x] == K) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 or nx < 0 or ny >= R or nx >= C) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] == 1) continue;

		visited[ny][nx] = visited[y][x]+1;
		DFS(ny, nx);
		visited[ny][nx] = 0;
	}

}


int main() {
	input();
	visited[R - 1][0] = 1;
	DFS(R - 1, 0);
	cout << ans;
}
