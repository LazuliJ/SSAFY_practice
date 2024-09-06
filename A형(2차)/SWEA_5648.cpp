// SWEA 5648 원자 소멸 시뮬레이션
// 일단 시뮬레이션류 노가다?
// 1000 * 1000 = 1,000,000 백만으로 실행 가능

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


// 원자 번호, 원자 x좌표, 원자 y좌표, 원자 방향, 원자 에너지
struct mole {
	int num;
	int x, y;
	int dir;
	int K;
};

// 원자의 충돌(총돌하는 원자1, 2, 충돌까지 걸리는 시간, 에너지)
struct crash {
	mole m1, m2;
	float ti;
	int energy;

	// 더 빨리 충돌하는 것부터.
	bool operator< (crash c1) const {
		if (ti > c1.ti) return true;
		if (ti < c1.ti) return false;

		return false;
	}
};

vector<mole> info; // 원자들의 모음
float visited[1000] = { 0, }; // 몇초에 충돌했는가?
int T;
int N;
int ans;
priority_queue<crash> pq; // 충돌 순서대로 정렬

//초기화
void init() {
	N = 0; ans = 0;
	info.clear();
	while (!pq.empty()) pq.pop();
	memset(visited, 0, sizeof(visited));
}

//입력
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		mole m;
		cin >> m.x >> m.y >> m.dir >> m.K;
		m.num = i;
		info.push_back(m);
	}
}

// 시뮬레이션
void sim() {
	// Part 1. 이 원자는 충돌하는 다른 원자가 있는가?
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			mole a = info[i]; mole b = info[j];
			crash C;
			// 동일한 방향으로 진행(만날 수 없음)
			if (a.dir == b.dir) continue;
			// 반대방향으로 진행하되 같은 줄에 있어서 만날 수 있음
			if (a.x == b.x && (a.dir == 0 && b.dir == 1 && a.y < b.y || a.dir == 1 && b.dir == 0 && a.y > b.y)) {
				C.ti = float(abs(a.y - b.y)) / 2;
				C.energy = a.K + b.K;
				C.m1 = a; C.m2 = b;
				pq.push(C);
				continue;
			}
			if (a.y == b.y && (a.dir == 2 && b.dir == 3 && b.x < a.x || a.dir == 3 && b.dir == 2 && b.x > a.x)) {
				C.ti = float(abs(a.x - b.x)) / 2;
				C.energy = a.K + b.K;
				C.m1 = a; C.m2 = b;
				pq.push(C);
				continue;
			}

			// 수직방향으로 만나는 경우
			if (a.dir == 0 && b.dir == 2 || a.dir == 3 && b.dir == 1) {
				if (b.x < a.x || b.y < a.y) continue;
				if (b.x - a.x == b.y - a.y) {
					C.ti = float(b.x - a.x);
					C.energy = a.K + b.K;
					C.m1 = a; C.m2 = b;
					pq.push(C);
				}
				continue;
			}
			if (a.dir == 0 && b.dir == 3 || a.dir == 2 && b.dir == 1) {
				if (a.x < b.x || b.y < a.y) continue;
				if (a.x - b.x == b.y - a.y) {
					C.ti = float(a.x - b.x);
					C.energy = a.K + b.K;
					C.m1 = a; C.m2 = b;
					pq.push(C);
				}
				continue;
			}
			if (a.dir == 1 && b.dir == 2 || a.dir == 3 && b.dir == 0) {
				if (b.x < a.x || a.y < b.y) continue;
				if (b.x - a.x == a.y - b.y) {
					C.ti = float(b.x - a.x);
					C.energy = a.K + b.K;
					C.m1 = a; C.m2 = b;
					pq.push(C);
				}
				continue;
			}
			if (a.dir == 1 && b.dir == 3 || a.dir == 2 && b.dir == 0) {
				if (a.x < b.x || a.y < b.y) continue;
				if (a.x - b.x == a.y - b.y) {
					C.ti = float(a.x - b.x);
					C.energy = a.K + b.K;
					C.m1 = a; C.m2 = b;
					pq.push(C);
				}
				continue;
			}
		}
	}

	// Part 2. 실제로 어떤 원자가 언제 충돌하는가?
	while(!pq.empty()) {
		crash crash_fast = pq.top(); pq.pop();
		if (visited[crash_fast.m1.num] != 0 && visited[crash_fast.m2.num] != 0) continue;
		if (visited[crash_fast.m1.num] != 0 && visited[crash_fast.m2.num] == 0) {
			if (visited[crash_fast.m1.num] == crash_fast.ti) {
				visited[crash_fast.m2.num] = crash_fast.ti;
				ans += crash_fast.m2.K;
			}
			continue;
		}
		if (visited[crash_fast.m1.num] == 0 && visited[crash_fast.m2.num] != 0) {
			if (visited[crash_fast.m2.num] == crash_fast.ti) {
				visited[crash_fast.m1.num] = crash_fast.ti;
				ans += crash_fast.m1.K;
			}
			continue;
		}
		visited[crash_fast.m1.num] = crash_fast.ti;
		visited[crash_fast.m2.num] = crash_fast.ti;
		ans += crash_fast.energy;
	}
}

// main
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		sim();
		cout << "#" << t << " " << ans << endl;
	}
}
