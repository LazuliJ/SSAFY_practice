//15650번 N과 M(2)
#include <iostream>

using namespace std;
int numbers[8] = { 0, };
int N, M;

void DFS(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << numbers[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (depth != 0 and numbers[depth - 1] >= i) continue;
		numbers[depth] = i;
		DFS(depth + 1);
		numbers[depth] = 0;
	}
}

int main() {
	cin >> N >> M;
	DFS(0);
}
