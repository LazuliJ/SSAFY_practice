// 백준 14889번 스타트와 링크 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int MAP[20][20] = { 0, };
int visited[20] = { 0, };
int ans = 10000;
int teamA[10], teamB[10];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

// N=10이상이고 뽑은 수를 다시 뽑지 않을 때 
// idx부터 시작하여 다음수부터 탐색을 시작해 실행시간을 줄일 수 있음.
void DFS(int depth, int idx) {
	if (depth == N / 2) {
		int sumA = 0, sumB = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] and visited[j])
					sumA += MAP[i][j];
				else if (!visited[i] and !visited[j])
					sumB += MAP[i][j];
			}
		}
		int tmp = abs(sumA - sumB);
		if (tmp < ans) ans = tmp;
		return;
	}

	for (int i = idx; i < N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		DFS(depth + 1, i+1);
		visited[i] = 0;
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
