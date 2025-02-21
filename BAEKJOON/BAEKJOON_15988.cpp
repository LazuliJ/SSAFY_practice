#include <iostream>

using namespace std;
typedef long long ll;

// DP - 백준 15988번 1, 2, 3 더하기 3

int T;
ll NUM = 1000000009;
ll ans[1000001] = { 0, };

void DP() {
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;

	// 점화식: A(n) = A(n-1) + A(n-2) + A(n-3)
	for (int i = 4; i <= 1000000; i++) {
		ans[i] = ((ans[i - 3]) % NUM + (ans[i - 2]) % NUM + (ans[i - 1]) % NUM) % NUM;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	DP();

	for (int t = 1; t <= T; t++) {
		ll n;
		cin >> n;
		cout << ans[n] << "\n";
	}
}
