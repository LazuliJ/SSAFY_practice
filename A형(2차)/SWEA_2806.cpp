// SWEA 2806 N-Queen

/*
원래 웰노운이라 고민할 것도 없겠지만
그냥 단순히 y를 depth로 잡고 x와 대각선 겹치면 안되니까
체크하면서 겹치면 쳐내면 된다.
*/

#include <iostream>

using namespace std;

int MAP[10][10] = { 0, }; // N*N, 퀸 대각선으로 놓을 수 있게 1로 표기
int visited_x[10] = { 0, }; // 이미 있는 x 값 ; y는 depth기 때문에 필요X
int ans = 0; // NQueen 성공!

void init() {
	ans = 0;
	for (int i = 0; i < 10; i++) {
		visited_x[i] = 0;
		for (int j = 0; j < 10; j++) {
			MAP[i][j] = 0;
		}
	}
}

int T, N;

void DFS(int depth) {
	if (depth == N) {
		ans++; return;
	}
	for (int i = 0; i < N; i++) {
		// 가로
		if (visited_x[i] == 1) continue;
		// 대각선
		int flag = 1;
		for (int k = 1; k < N; k++) {
			int ny = depth - k; int nx = i - k;
			if (ny <0 or nx < 0) break;
			if (MAP[ny][nx] == 1) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) continue;
		for (int k = 1; k < N; k++) {
			int ny = depth - k; int nx = i + k;
			if (ny < 0 or nx >= N) break;
			if (MAP[ny][nx] == 1) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) continue;

		visited_x[i] = 1;
		MAP[depth][i] = 1;
		DFS(depth + 1);
		MAP[depth][i] = 0;
		visited_x[i] = 0;
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> N;
		DFS(0);
		cout << "#" << t << " " << ans << "\n";
	}
}
