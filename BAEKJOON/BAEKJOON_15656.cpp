// 15656번 N과 M(7) - 백트래킹
#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[7];
int ans[7];

void DFS(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n"; // 생각보다 시간단축이 많이 됨.
		return;
	}
	for (int i = 0; i < N; i++) {
		ans[depth] = arr[i];
		DFS(depth+1);
		ans[depth] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	DFS(0);
}
