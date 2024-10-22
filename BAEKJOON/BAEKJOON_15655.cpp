// 15655번 N과 M(6)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numbers[8] = { 0, };
vector<int> vec;
int visited[8] = { 0, };
int N, M;

void DFS(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << numbers[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (visited[i] == 1) continue;
		if (depth != 0 and numbers[depth - 1] >= vec[i]) continue;
		visited[i] = 1;
		numbers[depth] = vec[i];
		DFS(depth + 1);
		numbers[depth] = 0;
		visited[i] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	DFS(0);
}
