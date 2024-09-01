// SWEA 10966번 물놀이를 가자.

#include <iostream>
#include <queue>

using namespace std;

int T; //테케 개수
int N, M; // 가로, 세로
int MAP[1000][1000];
int visited[1000][1000];
queue<int> q;
int ans = 0;

void init() {
	ans = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			MAP[i][j] = 0;
			visited[i][j] = 0;
		
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch;
			cin >> ch;

			if (ch == 'W') {
				MAP[i][j] = -1;
				q.push(i);
				q.push(j);
			}
		}
	}
}

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void BFS() {
	while (!q.empty()) {
		int iy = q.front(); q.pop();  int ix = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = iy + dy[i]; int nx = ix + dx[i];
			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (MAP[ny][nx] == -1 or visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[iy][ix] + 1;
			ans += visited[ny][nx];
			q.push(ny); q.push(nx);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		BFS();
		cout << "#" << t << " " << ans << "\n";
	}
}
