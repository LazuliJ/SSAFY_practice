// 백준 10845번 큐

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main() {
	cin >> N;
	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (str == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			cout << q.empty() << endl;
		}
		else if (str == "front") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else if (str == "back") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}
}
