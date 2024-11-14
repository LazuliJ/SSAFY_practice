#include <iostream>
#include <algorithm>

using namespace std;

// 백준 11265번 끝나지 않는 파티
// 플로이드-워셜 알고리즘 기본 문제

int N, M;
long long MAP[501][501] = { 0, };

void init() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			if (i == j) continue;
			MAP[i][j] = 1000001;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
}

void FW() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int t = 1; t <= N; t++) {
				if (i == j or j == t or i == t) continue;
				MAP[j][t] = min(MAP[j][t], MAP[j][i] + MAP[i][t]);
			}
		}
	}
}

void display() {
	int A, B;
	long long C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		if (MAP[A][B] <= C) cout << "Enjoy other party\n";
		else cout << "Stay here\n";
	}
}

int main() {
	init();
	input();
	FW();
	display();
}
