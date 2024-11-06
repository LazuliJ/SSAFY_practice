#include <iostream>
#include <deque>
#include <cmath> // pow 쓰려면 반드시 필요

using namespace std;

// 백준 1430번 공격

/*******************************************************/
// 탑의 개수, 사정 거리, 초기 에너지, 적의 X좌표, 적의 Y좌표
int N, R, D, Xe, Ye;
int towers[50][2] = { 0, };
int visited[50] = { 0, };
float ans = 0;

deque<int> q;
/*******************************************************/

// 입력
void input() {
	cin >> N >> R >> D >> Xe >> Ye;
	for (int i = 0; i < N; i++) {
		cin >> towers[i][0] >> towers[i][1];
		if (pow((towers[i][0] - Xe), 2) + pow((towers[i][1] - Ye), 2) <= pow(R, 2)) {
			visited[i] = 1;
			q.push_back(i);
		}
	}
}

// BFS형식으로 탐색
void sol() {
	while (!q.empty()) {
		int n = q.front(); q.pop_front();
		for (int i = 0; i < N; i++) {
			if (visited[i] != 0) continue;
			if (pow((towers[i][0] - towers[n][0]), 2) + pow((towers[i][1] - towers[n][1]), 2) <= pow(R, 2)) {
				visited[i] = visited[n]+1;
				q.push_back(i);
			}
		}
	}
}

// main
int main() {
	input();
	sol();
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) continue;
		float tmp_ans = D;
		for (int j = 1; j < visited[i]; j++) {
			tmp_ans /= 2;
		}
		ans += tmp_ans;
	}
	cout << ans;
}
