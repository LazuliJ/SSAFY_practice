// 백준 14502번 연구소
/*
1. DFS 및 BFS라고 생각한 이유
맵 크기 8*8, 벽 3개, 제한 시간 2초 등 숫자가 작위적임.
딱히 벽 위치 선정에 있어서 규칙이나 이유가 없음.
-> 완탐일 확률 높다.

2. 문제의 특이사항: DFS안에 BFS를 넣어서
DFS로 벽 위치를 선정하고, BFS로 안전지대 개수를 센다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int MAP[8][8] = { 0, };
int ans = 0;
vector<int> o_virus; // BFS를 위한 바이러스 좌표 원본

// init && input
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				o_virus.push_back(i);
				o_virus.push_back(j);
			}
		}
	}
}

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void DFS(int depth, int last_num) {
	// 좌표를 3개 고른다.
	if (depth == 3) {
		// 메모리 초과/ 오류시 밖으로 뺄 예정
		// BFS 전처리
		int visited[8][8] = { 0, };
		queue<int> q;
		for (int i = 0; i < o_virus.size(); i++) {
			q.push(o_virus[i]);
		}

		// BFS
		while (!q.empty()) {
			int y = q.front(); q.pop();
			int x = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
				if (MAP[ny][nx] == 2) continue;
				if (MAP[ny][nx] == 1) continue;
				if (visited[ny][nx] == 1) continue;
				visited[ny][nx] = 1;
				q.push(ny);
				q.push(nx);
			}
		}
		
		int cnt = 0;
		// 정답 구하기
		for (int i = 0; i < N*M; i++) {
			if (MAP[i / M][i%M] == 0 and visited[i / M][i%M] == 0) cnt++;
		}
		if (cnt > ans) ans = cnt;
		return;
	}
	// 시간 초과 방지를 위해 겹치는 조합을 고르지 않게함.
	for (int i = last_num; i < N*M; i++) {
		if (MAP[i / M][i%M] == 2) continue;
		if (MAP[i / M][i%M] == 1) continue;
		MAP[i / M][i%M] = 1;
		DFS(depth + 1, i+1);
		MAP[i / M][i%M] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	DFS(0, 0);
	cout << ans;
}
