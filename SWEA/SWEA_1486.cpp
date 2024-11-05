#include <iostream>
#include <vector>
#include <algorithm>

// SWEA 1486 장훈이의 높은 선반

using namespace std;

/*************************/
int T;
int N, B;
int vec[20] = { 0, };
int visited[20] = { 0, };
int ans = 200000;
/*************************/

// 초기화
void init() {
	ans = 200000;
	for (int i = 0; i < 20; i++) {
		vec[i] = 0;
	}
}

// 입력
void input() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	sort(vec, vec + N, greater<>());
}

// end안하면 모든 조합으로 시도하므로 (같은 수들이라도) 시간초과가 난다. 
// 백트래킹
void DFS(int sum, int end) {
	if (sum >= B) {
		if (ans > sum - B) ans = sum - B;
		return;
	}

	for (int i = end; i < N; i++) {
		if (visited[i] == 1) continue;
		if (sum + vec[i] >= ans + B) continue;
		visited[i] = 1;
		DFS(sum + vec[i], i+1);
		visited[i] = 0;
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

		DFS(0, 0);
		cout << "#" << t << " " << ans << "\n";
	}
}
