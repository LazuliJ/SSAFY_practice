#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 백준 1477번 휴게소 세우기

// 사용 알고리즘: priority queue 및 그리디
// 사용 알고리즘이 틀렸음. (이분 탐색(매개변수 탐색) 활용)

int N, M, L;
vector<int> vec;
priority_queue<int> pq;

void input() {
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		vec.push_back(t);
	}
}

void init() {
	sort(vec.begin(), vec.end());
	if (!vec.empty()) pq.push(vec[0] - 0);
	for (int i = 1; i < N; i++) {
		pq.push(vec[i] - vec[i - 1]);
	}
	if (!vec.empty()) pq.push(L - vec[N-1]);
}

void make_convi() {
	int big_num = pq.top(); pq.pop();
	if (big_num % 2 == 0) {
		pq.push(big_num / 2); pq.push(big_num / 2);
	}
	else {
		pq.push(big_num / 2 + 1); pq.push(big_num / 2);
	}
}

int main() {
	input();
	init();
	for (int i = 0; i < M; i++) {
		make_convi();
	}
	cout << pq.top();
}
