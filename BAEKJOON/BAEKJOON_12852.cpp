#include <iostream>

using namespace std;

// 백준 12852번 1로 만들기 2

/****************************/
int N;
int dp[1000001] = { 0, };
int dp_past[1000001] = { 0, }; // 역추적을 위해 전단계의 숫자를 삽입
/****************************/

// input
void init() {
	cin >> N;
}

// dp
// 구하는 것 = 연산의 최소 횟수
// 지금 연산의 최소 횟수 = 전단계 + 1

void dp_sol() {
	
	for (int i = 2; i <= N; i++) {
		if (i % 3 == 0) {
			if (dp[i] == 0 or dp[i / 3] + 1 < dp[i]) {
				dp[i] = dp[i / 3] + 1;
				dp_past[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (dp[i] == 0 or dp[i / 2] + 1 < dp[i]) {
				dp[i] = dp[i / 2] + 1;
				dp_past[i] = i / 2;
			}
		}
		if (dp[i] == 0 or dp[i - 1] + 1 < dp[i]) {
			dp[i] = dp[i - 1] + 1;
			dp_past[i] = i - 1;
		}
	}
}

// main
int main() {
	init();
	dp_sol();
	int n = N;
	cout << dp[n] << '\n';
	while (n != 0) {
		cout << n << " ";
		n = dp_past[n];
	}
}
