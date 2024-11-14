#include <iostream>
#include <algorithm>

using namespace std;

// 백준 1956번 운동
// 플로이드-워셜을 이용한 최소 거리 및 왕복거리 구하기
/*
MAP의 초기값 크기에 주의한다.
초기값이 10001이라면 큰 사이클 (1->2->3... -> 400->1, 길이는 모두 10000)
같은 케이스에서 계산 불가함을 주의할 것.
*/

/*
solved에서의 말에 따르면 플로이드 워셜에서 자기자신으로 가는 
최단 거리를 INF로 설정한 후 실행하면 바로 자신으로 돌아오는 최소
거리를 구할 수 있다고 한다.
*/

/**************************/
int V, E; // 마을 V개, 도로 E개
long long MAP[401][401] = { 0, }; // 각 마을 사이의 최소 이동거리
long long ans = -1; // 운동 경로 (정답)
/**************************/

// 초기화
void init() {
	for (int i = 1; i < 401; i++) {
		for (int j = 1; j < 401; j++) {
			MAP[i][j] = 40000001;
		}
	}
}

// 입력 받기
void input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		MAP[a][b] = c;
	}
}

// 플로이드-워셜로 두 거리를 이동하는데 드는 최소 거리를 구함
void FW() {
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (i == j or j == k or k == i) continue;
				MAP[j][k] = min(MAP[j][k], MAP[j][i] + MAP[i][k]);
			}
		}
	}
}

// 어떤 두 거리를 최소로 왕복할 때 해당 거리들의 합
void run() {
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (MAP[i][j] == 40000001 or MAP[j][i] == 40000001) continue;
			long long tmp = MAP[i][j] + MAP[j][i];
			if (ans == -1) ans = tmp;
			else ans = min(ans, tmp);
		}	
	}
}

// main
int main() {
	init();
	input();
	FW();
	run();
	cout << ans;
}
