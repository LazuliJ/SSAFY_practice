// SWEA 7465 창용 마을 무리의 개수 Union Find

#include <iostream>

using namespace std;

int visited[101] = { 0, };
int parent[101] = { 0, };

int T;

int Find(int A) {
	if (parent[A] == A) return A;
	return parent[A] = Find(parent[A]);
}

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);

	parent[rootB] = rootA;
}

int main() {
	cin >> T;
	int N, M;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < 101; i++) {
			parent[i] = i;
			visited[i] = 0;
		}
		int cnt = 0;
		int a, b;
		for (int j = 0; j < M; j++) {
			cin >> a >> b;
			Union(a, b);
		}

		for (int j = 1; j <= N; j++) {
			if (visited[Find(j)] == 1) continue;
			visited[Find(j)] = 1;
			cnt++;
		}

		cout << "#" << t << " " << cnt << endl;
	}

}
