// 백준 16236번 아기 상어
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
1. 같은 깊이의 DFS를 모두 구하지 않으면 반례에 걸린다.
0 0 1
1 9 1
1 0 0 에서 밑의 1이 먼저 선택된다.

2. 같은 깊이를 어떻게 구할 것인가 >> 뽑아서 정답 길이보다 짧으면 방향배열을 사용하지 않으면 된다.
*/

int N;
int MAP[20][20] = { 0, };
int visited[20][20];
int sh_size = 2; // 상어 사이즈
int cnt = 0; // 물고기를 몇마리 먹었는가?
int ans = 0; // 정답
int nowy, nowx; 
bool flag = false; // 먹을 수 있는 물고기를 다 먹었는가?

// 같은 깊이의 물고기 위치 sort 위함.
struct elem {
	int y, x;
	bool operator< (elem e) const {
		if (y < e.y) return true;
		if (y > e.y) return false;

		if (x < e.x) return true;
		if (x > e.x) return false;

		return false;
	}
};

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				nowy = i;
				nowx = j;
			}
		}
	}
}

// 방향배열
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

void Flood(int y, int x) {
	queue<int> q;
	int flood_depth = 0;
	vector<elem> vec;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = -1;
		}
	}
	q.push(y);
	q.push(x);
	visited[y][x] = 0;
	MAP[y][x] = 401; // << 상어를 0으로 만들면 갈 출발 위치가 아니라 갈 수 있는 위치 되므로 중복을 피하기 위해

	while (!q.empty()) {
		int iy = q.front(); q.pop();
		int ix = q.front(); q.pop();
		if (flood_depth != 0 and visited[iy][ix] >= flood_depth) // <<
			continue;

		for (int i = 0; i < 4; i++) {
			int ny = iy + dy[i];
			int nx = ix + dx[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= N) continue;
			if (visited[ny][nx] != -1) continue;
			if (MAP[ny][nx] > sh_size) continue;
			visited[ny][nx] = visited[iy][ix] + 1;
			if (MAP[ny][nx] != 0 and MAP[ny][nx] < sh_size) { // <<
				if (flood_depth == 0) flood_depth = visited[ny][nx]; // <<
				if (flood_depth == visited[ny][nx]) vec.push_back({ ny, nx }); // <<
			} // <<
			q.push(ny); q.push(nx);

		}
	}
	MAP[y][x] = 0;
	if (vec.size() != 0) {
		sort(vec.begin(), vec.end());
		nowy = vec[0].y;
		nowx = vec[0].x;
		MAP[nowy][nowx] = 9;
		cnt++;
		ans += flood_depth;
		if (cnt == sh_size) {
			cnt = 0;
			sh_size++;
		}
	}
	else {
		flag = true;
	}
}

int main() {
	input();
	while (1) {
		Flood(nowy, nowx);
		if (flag == true) break;
	}
	cout << ans;
}
