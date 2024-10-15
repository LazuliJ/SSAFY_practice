// 9095번 1, 2, 3 더하기

#include <iostream>

using namespace std;

int T;
int n;
int ans = 0;

void find(int N) {
	if (N == n) {
		ans++;
		return;
	}
	else if (N > n) {
		return;
	}

	for (int i = 1; i < 4; i++) {
		find(N + i);
	}
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		n = 0; ans = 0;
		cin >> n;
		find(0);
		cout << ans << endl;
	}
}
