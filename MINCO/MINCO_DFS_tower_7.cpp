// 민코딩 DFS의 탑 7번
#include <iostream>
#include <vector>
#include <queue>

// 굳이 Node 안만들어도 vector 2개를 이용해서 각각 완탐하면 된다. 

using namespace std;

struct Node {
	vector<int> prev;
	vector<int> next;
};

int visited_next[100001] = { 0 };
int visited_prev[100001] = { 0 };
Node nd[100001];
int A = 0; int B = 0;

int N, M, X;

void BFS_next() {
	queue<int> q;
	q.push(X);

	while (!q.empty()) {
		int tar = q.front(); q.pop();
		for (int i = 0; i < nd[tar].next.size(); i++) {
			if (visited_next[nd[tar].next[i]] == 1) continue;
			A++;
			visited_next[nd[tar].next[i]] = 1;
			q.push(nd[tar].next[i]);
		}
	}
}

void BFS_prev() {
	queue<int> q;
	q.push(X);

	while (!q.empty()) {
		int tar = q.front(); q.pop();
		for (int i = 0; i < nd[tar].prev.size(); i++) {
			if (visited_prev[nd[tar].prev[i]] == 1) continue;
			B++;
			visited_prev[nd[tar].prev[i]] = 1;
			q.push(nd[tar].prev[i]);
		}
	}
}


int main() {
	cin >> N >> M >> X;
	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;
		nd[a].prev.push_back(b);
		nd[b].next.push_back(a);
	}
	BFS_next();
	BFS_prev();
	cout << A + 1 << endl;
	cout << N - B << endl;
}
