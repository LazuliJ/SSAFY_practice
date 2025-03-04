#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

// 백준 16234번 인구 이동 - 시뮬레이션 + BFS

int N, L, R;
int ans = 0;

int A[51][51] = { 0, };
int visited[51][51] = { 0, };

vector<vector<int>> vec;
vector<int> total_person;
deque<int> dq;

void init() {
	while (!total_person.empty()) {
		total_person.pop_back();
		vec.pop_back();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}

}

void input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
}

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void flood_fill() {
	int num = vec.size() + 1;
	vector<int> tmp_vec;
	while (!dq.empty()) {
		int y = dq.front(); dq.pop_front();
		int x = dq.front(); dq.pop_front();
		total_person[num - 1] += A[y][x];
		tmp_vec.push_back(y); tmp_vec.push_back(x);

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 or ny >= N or nx < 0 or nx >= N) continue;
			if (visited[ny][nx] != 0) continue;
			int diff = abs(A[y][x] - A[ny][nx]);
			if (diff >= L and diff <= R) {
				dq.push_back(ny);
				dq.push_back(nx);
				visited[ny][nx] = num;
			}
		}
	}
	vec.push_back(tmp_vec);
}

int pass_day() {
	int if_changed = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int need_change = 0;
			// flood fill이 필요한지 조건검사
			if (visited[i][j] != 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int y = i + dy[dir];
				int x = j + dx[dir];
				if (y < 0 or x < 0 or y >= N or x >= N) continue;
				int diff_person = abs(A[i][j] - A[y][x]);
				if (diff_person >= L and diff_person <= R) {
					need_change = 1;
					dq.push_back(y);
					dq.push_back(x);
					visited[y][x] = vec.size() + 1;
				}
			}
			if (need_change == 0) visited[i][j] = -1;
			// 필요하다면 flood fill
			else {
				visited[i][j] = vec.size() + 1;
				total_person.push_back(A[i][j]);
				if_changed = 1;
				flood_fill();
				vec[vec.size() - 1].push_back(i);
				vec[vec.size() - 1].push_back(j);
			}
		}
	}

	// 국경 개방 및 연합 구성이 끝났으므로 인구수 구하기
	for (int i = 0; i < total_person.size(); i++) {
		int cur_person = floor(total_person[i] / int(vec[i].size()/2));
		while (!vec[i].empty()) {
			int x = vec[i].back(); vec[i].pop_back();
			int y = vec[i].back(); vec[i].pop_back();
			//cout << x << y;

			A[y][x] = cur_person;
		}
	}

	return if_changed;
}

// test code
void print_A() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	while (true) {
		init();
		if (pass_day() == 0) break;
		else ans++;
		//print_A();
	}

	cout << ans;
}
