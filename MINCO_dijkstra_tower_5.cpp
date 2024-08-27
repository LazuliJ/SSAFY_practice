// Mincoding dijkstra의 탑 5번

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int n;
	int value;

	bool operator< (Edge right) const {
		return value > right.value;
	}
};

int distSTT[5001];
int distHS[5001];

vector<Edge> alias[5001];

void dijkstra(int stnum, int *dist) {
	priority_queue<Edge> pq;
	for (int i = 0; i < 5001; i++) {
		*(dist + i) = 21e8;
	}
	pq.push({ stnum, 0 });
	*(dist + stnum) = 0;

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		if (now.value > *(dist + now.n)) continue;
		for (int i = 0; i < alias[now.n].size(); i++) {
			Edge next = alias[now.n][i];
			int nextnum = *(dist + now.n) + next.value;
			if (nextnum > *(dist + next.n)) continue;
			*(dist + next.n) = nextnum;
			pq.push({ next.n, nextnum });
		}
	}
}

int V, E, P;

int main() {
	cin >> V >> E >> P;
	for (int i = 0; i < E; i++) {
		int u, v, leng;
		cin >> u >> v >> leng;
		alias[u].push_back({ v, leng });
		alias[v].push_back({ u, leng });
	}
	dijkstra(1, distHS);
	dijkstra(P, distSTT);

	if (distHS[V] == distSTT[1] + distSTT[V]) {
		cout << "OKAY";
	}
	else {
		cout << "SORRY";
	}
}
