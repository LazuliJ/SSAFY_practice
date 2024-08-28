#include <iostream>
#include <queue>

using namespace std;

int N, H;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	cin >> N >> H;
	for (int n = 0; n < N; n++) {
		int tmp;
		cin >> tmp;

		pq.push(tmp);
	}

	for (int n = 0; n < N; n++) {
		int t = pq.top(); pq.pop();
		H -= t;

		if (H <= 0) break;
	}

	if (H <= 0) cout << N - pq.size();
	else cout << -1;

}
