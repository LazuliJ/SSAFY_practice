// 백준 11724번 - 실버 2 (SWEA 7465번 유사유형)
// 유니온 파인드
#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int parent[1001] = { 0, };

int Find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = Find(parent[node]);
}

void Union(int n1, int n2) {
	int root1 = Find(n1);
	int root2 = Find(n2);

	parent[root2] = root1;
}

int main() {
	cin >> N >> M;
	// parent 초기 세팅 / 범위 유의 (1000 이하)
	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		Union(u, v);
	}

	// 만약 다른 노드와 연결되었다면 parent가 자기자신일 수 없음.
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (parent[i] == i) cnt++;
	}
	cout << cnt;
}
