#include <iostream>

using namespace std;
typedef long long ll;

// 백준 2156번 포도주 시식
// DP
// 최대 3잔이므로 0, 1, 2잔을 연속으로 마신 경우에 대해 계산한다.

int n;
int wine[10001] = { 0, };
ll total_wine[10001][3] = {0,};

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}
	total_wine[0][1] = wine[0];
}

void DP(int cur) {
	for (int i = 0; i < 3; i++) {
		total_wine[cur][0] = max(total_wine[cur - 1][i], total_wine[cur][0]);
	}
	total_wine[cur][1] = total_wine[cur-1][0] + wine[cur];
	total_wine[cur][2] = total_wine[cur-1][1] + wine[cur];
}

int main() {
	input();
	for (int i = 1; i < n; i++) {
		DP(i);
	}
	ll ans = 0;
	for (int i = 0; i < 3; i++) {
		ans = max(total_wine[n - 1][i], ans);
	}
	cout << ans;
}
