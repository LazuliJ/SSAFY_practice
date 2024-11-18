#include <iostream>

using namespace std;

// 백준 11727번 2 * n 타일링 2 - dp

/*********************/
int n;
int dp[1001] = { 0, };
/*********************/

// input
void input() {
	cin >> n;
}

// dp: 현재 방법의 수 = i-1번째 수 * 1 + i-2번째 수 * 2
void dp_sol() {
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
}

// main
int main() {
	input();
	dp_sol();
	cout << dp[n];
}
