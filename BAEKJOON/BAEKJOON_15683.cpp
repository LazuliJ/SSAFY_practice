// 백준 15683번

/*
CCTV 개수 8개에서 알 수 있듯이 그냥저냥 평범한 DFS 문제
근데 구현이 복잡해서 실수하기가 쉽다.

이번에 실수한 곳은 _cnt와 _visited를 바깥에다가 만든 것.
이러면 depth가 진전될 때 다른 정보가 visited에 저장되고, 이에 따라 전에 저장되었던 visited가 덮어쓰기 될 수 있다.
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M; //세로, 가로
int MAP[8][8] = { 0, };
int visited[8][8] = { 0, };
vector<vector<int>> vec; //cctv 좌표들
int cnt, ans = 64; //현재 사각지대의 수, 최소 사각지대의 수(정답)


// 입력
void input() {
	cin >> N >> M;
	cnt = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] != 0) {
				cnt--;
				visited[i][j] = 1;
			}
			if (MAP[i][j] != 0 and MAP[i][j] != 6) {
				vec.push_back({ i, j });
			}
		}
	}
}

// (+y, -y, +x, -x)
int cctv1[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };
int cctv2[2][4] = { {1, 1, 0, 0}, {0, 0, 1, 1} };
int cctv3[4][4] = { {1, 0, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 0, 1} };
int cctv4[4][4] = { {1, 1, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 1, 1} };
int cctv5[1][4] = { {1, 1, 1, 1} };

void DFS(int depth) {
	if (depth == vec.size()) {
		if (cnt < ans) ans = cnt;
		return;
	}
	
	int y = vec[depth][0];
	int x = vec[depth][1];
	int cctv_num = MAP[y][x];
	int _cnt = cnt;
	int _visited[8][8] = { 0, };

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			_visited[n][m] = visited[n][m];
		}
	}

	if (cctv_num == 1) {

		for (int ver = 0; ver < 4; ver++) {
			// + y
			if (cctv1[ver][0] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y + i >= N) break;
					if (MAP[y + i][x] == 6) break;
					visited[y + i][x]++;
					if (visited[y + i][x] == 1) cnt--;
				}
			}

			if (cctv1[ver][1] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) break;
					if (MAP[y - i][x] == 6) break;
					visited[y - i][x]++;
					if (visited[y - i][x] == 1) cnt--;
				}
			}

			if (cctv1[ver][2] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x + i >= M) break;
					if (MAP[y][x+i] == 6) break;
					visited[y][x + i]++;
					if (visited[y][x + i] == 1) cnt--;
				}
			}

			if (cctv1[ver][3] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x - i  < 0) break;
					if (MAP[y][x-i] == 6) break;
					visited[y][x - i]++;
					if (visited[y][x - i] == 1) cnt--;
				}
			}

			DFS(depth + 1);

			cnt = _cnt;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					visited[n][m] = _visited[n][m];
				}
			}
		}
	}

	if (cctv_num == 2) {

		for (int ver = 0; ver < 2; ver++) {
			// + y
			if (cctv2[ver][0] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y + i >= N) break;
					if (MAP[y + i][x] == 6) break;
					visited[y + i][x]++;
					if (visited[y + i][x] == 1) cnt--;
				}
			}

			if (cctv2[ver][1] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) break;
					if (MAP[y - i][x] == 6) break;
					visited[y - i][x]++;
					if (visited[y - i][x] == 1) cnt--;
				}
			}

			if (cctv2[ver][2] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x + i >= M) break;
					if (MAP[y][x + i] == 6) break;
					visited[y][x + i]++;
					if (visited[y][x + i] == 1) cnt--;
				}
			}

			if (cctv2[ver][3] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) break;
					if (MAP[y][x - i] == 6) break;
					visited[y][x - i]++;
					if (visited[y][x - i] == 1) cnt--;
				}
			}

			DFS(depth + 1);

			cnt = _cnt;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					visited[n][m] = _visited[n][m];
				}
			}
		}
	}

	if (cctv_num == 3) {

		for (int ver = 0; ver < 4; ver++) {
			// + y
			if (cctv3[ver][0] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y + i >= N) break;
					if (MAP[y + i][x] == 6) break;
					visited[y + i][x]++;
					if (visited[y + i][x] == 1) cnt--;
				}
			}

			if (cctv3[ver][1] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) break;
					if (MAP[y - i][x] == 6) break;
					visited[y - i][x]++;
					if (visited[y - i][x] == 1) cnt--;
				}
			}

			if (cctv3[ver][2] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x + i >= M) break;
					if (MAP[y][x + i] == 6) break;
					visited[y][x + i]++;
					if (visited[y][x + i] == 1) cnt--;
				}
			}

			if (cctv3[ver][3] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) break;
					if (MAP[y][x - i] == 6) break;
					visited[y][x - i]++;
					if (visited[y][x - i] == 1) cnt--;
				}
			}

			DFS(depth + 1);

			cnt = _cnt;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					visited[n][m] = _visited[n][m];
				}
			}
		}
	}

	if (cctv_num == 4) {

		for (int ver = 0; ver < 4; ver++) {
			// + y
			if (cctv4[ver][0] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y + i >= N) break;
					if (MAP[y + i][x] == 6) break;
					visited[y + i][x]++;
					if (visited[y + i][x] == 1) cnt--;
				}
			}

			if (cctv4[ver][1] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) break;
					if (MAP[y - i][x] == 6) break;
					visited[y - i][x]++;
					if (visited[y - i][x] == 1) cnt--;
				}
			}

			if (cctv4[ver][2] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x + i >= M) break;
					if (MAP[y][x + i] == 6) break;
					visited[y][x + i]++;
					if (visited[y][x + i] == 1) cnt--;
				}
			}

			if (cctv4[ver][3] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) break;
					if (MAP[y][x - i] == 6) break;
					visited[y][x - i]++;
					if (visited[y][x - i] == 1) cnt--;
				}
			}

			DFS(depth + 1);

			cnt = _cnt;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					visited[n][m] = _visited[n][m];
				}
			}
		}
	}

	if (cctv_num == 5) {

		for (int ver = 0; ver < 1; ver++) {
			// + y
			if (cctv5[ver][0] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y + i >= N) break;
					if (MAP[y + i][x] == 6) break;
					visited[y + i][x]++;
					if (visited[y + i][x] == 1) cnt--;
				}
			}

			if (cctv5[ver][1] == 1) {
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) break;
					if (MAP[y - i][x] == 6) break;
					visited[y - i][x]++;
					if (visited[y - i][x] == 1) cnt--;
				}
			}

			if (cctv5[ver][2] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x + i >= M) break;
					if (MAP[y][x + i] == 6) break;
					visited[y][x + i]++;
					if (visited[y][x + i] == 1) cnt--;
				}
			}

			if (cctv5[ver][3] == 1) {
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) break;
					if (MAP[y][x - i] == 6) break;
					visited[y][x - i]++;
					if (visited[y][x - i] == 1) cnt--;
				}
			}

			DFS(depth + 1);

			cnt = _cnt;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					visited[n][m] = _visited[n][m];
				}
			}
		}
	}
}

int main() {
	input();
	DFS(0);

	cout << ans;
}
