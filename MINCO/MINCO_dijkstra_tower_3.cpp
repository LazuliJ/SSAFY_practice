// Mincoding dijkstra의 탑 3번

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int n;
	int val;

	bool operator< (Edge right) const {
		return val > right.val;
	}
};

int N, M;
int MAP[100][100];
vector<Edge> alias[10000];
int dist[10000];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void dijkstra() {
	priority_queue<Edge> pq;

	pq.push({ 0, MAP[0][0] });

	for (int i = 0; i < 10000; i++) {
		dist[i] = 21e8;
	}
	
	dist[0] = MAP[0][0];

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();

		if (now.val > dist[now.n]) continue;

		for (int i = 0; i < alias[now.n].size(); i++) {
			Edge next = alias[now.n][i];

			int nextsum = dist[now.n] + next.val;
			
			if (nextsum > dist[next.n]) continue;

			dist[next.n] = nextsum;
			
			pq.push({ next.n, nextsum });
		}
		
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;

				alias[i * 100 + j].push_back({ ny * 100 + nx, MAP[ny][nx] });

			}
		}
	}

	dijkstra();

	cout << dist[100*(N-1)+(M-1)];
}
