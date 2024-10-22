//15649번 N과 M(1)
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
		int flag = 0;
		if (depth != 0) {
			for (int j = 0; j < depth; j++) {
				if (numbers[j] == i) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) continue;
		numbers[depth] = i;
		DFS(depth + 1);
		numbers[depth] = 0;
	}
}

int main() {
	cin >> N >> M;
	DFS(0);
}
