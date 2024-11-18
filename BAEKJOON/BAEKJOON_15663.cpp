#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 15663번 N과 M(9) - 백트래킹

int N, M;
int MAP[8];
int visited[8] = { 0, };
vector<int> vec;

void init() {
	for (int i = 0; i < 8; i++) {
		MAP[i] = 10001;
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
	sort(MAP, MAP + 8);
}

void BT(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (i != 0 and visited[i-1] == 0 and MAP[i] == MAP[i - 1]) continue; // 핵심조건
		if (visited[i] == 1) continue;
		vec.push_back(MAP[i]);
		visited[i] = 1;
		BT(depth + 1);
		visited[i] = 0;
		vec.pop_back();
	}
}

int main() {
	init();
	input();
	BT(0);
}
