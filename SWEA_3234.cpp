#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 하나씩 해보되 (N의 개수가 최대 9이므로 끝까지 모두)
// 오른쪽이 더 커지는 순간 배제

int T, N; int sumW;
int ans;
int weights[9];

void DFS(int depth, int a, int b, int wa) {
	if (depth == N - 1) { // sort 완료
		if (wa + b <= a) ans++;
		ans++;
		return;
	}
	if (sumW / 2 < b) return; // 백트래킹(중요 가지치기 조건)
	int wea = weights[depth + 1];
	if (a >= b + wa) DFS(depth + 1, a, b + wa, wea);
	DFS(depth + 1, a + wa, b, wea);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		// init
		ans = 0; sumW = 0;
		for (int i = 0; i < 9; i++) weights[i] = 0;
		cin >> N; sumW = 0;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			sumW += tmp;
			weights[i] = tmp;
		}
		sort(weights, weights+N);
		do {
			DFS(1, weights[0], 0, weights[1]);
		} while (next_permutation(weights, weights+N));
		cout << "#" << t << " " << ans << endl;
	}

}
