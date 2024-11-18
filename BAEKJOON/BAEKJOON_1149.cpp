#include <iostream>
#include <algorithm>

using namespace std;

// 1149번 RGB거리 - DP
// i번 집이 R(G, B)일 때 i-1번 집은 G/B(R/B, R/G)의 최소
// 이 방법으로 현재 집이 R/G/B일 때 가질 수 있는 최솟값을 출력

/**************************/
int N;
int MAP[1001][3] = { 0, };
int DP[1001][3] = { 0, };
/**************************/

// input
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> MAP[i][j];
		}
	}
}

// DP (Bottom-up)
void sol() {
	DP[1][0] = MAP[1][0]; DP[1][1] = MAP[1][1]; DP[1][2] = MAP[1][2];
	for (int i = 2; i <= N; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + MAP[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + MAP[i][1];
		DP[i][2] = min(DP[i - 1][1], DP[i - 1][0]) + MAP[i][2];
	}
}

// main
int main() {
	input();
	sol();
	if (DP[N][0] <= DP[N][1] and DP[N][0] <= DP[N][2]) {
		cout << DP[N][0];
	}
	else if (DP[N][1] <= DP[N][0] and DP[N][1] <= DP[N][2]) {
		cout << DP[N][1];
	}
	else if (DP[N][2] <= DP[N][1] and DP[N][2] <= DP[N][0]) {
		cout << DP[N][2];
	}
}
