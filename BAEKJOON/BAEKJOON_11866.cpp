// 백준 11866번 요세푸스 문제 0

#include <iostream>
#include <deque>

using namespace std;

int N, K;
deque<int> dq;
deque<int> ans;

int main() {
	cin >> N >> K;
	
	int now = K, next = 0;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (!dq.empty()) {
		for (int i = 0; i < K-1; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		ans.push_back(dq.front());
		dq.pop_front();
	}

	cout << "<";
	while (!ans.empty()) {
		cout << ans.front();
		ans.pop_front();
		if (!ans.empty()) {
			cout << ", ";
		}
	}
	cout << ">";
}
