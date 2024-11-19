#include <iostream>
#include <algorithm>

using namespace std;

// 백준 11055번 가장 큰 증가하는 부분 수열 - dp
/*
접근법: 이전에 지금 숫자보다 작은 수 중 합이 최대인 것 + 지금 수
처음에 lis처럼 단순하게 바로 전 숫자보다 크면 + 아니면 숫자
처럼 했으나
2 11 3 14 등의 반례에서 문제가 생김.
*/

/***********************/
int N;
int MAP[1001] = { 0, };
int dp[1001] = { 0, };
/***********************/

// input
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
}

// dp
void dp_sol() {
	dp[0] = MAP[0];
	for (int i = 1; i < N; i++) {
		int past_num = 0;

		for (int j = 0; j < i; j++) {
			if (MAP[j] < MAP[i] and past_num < dp[j]) {
				past_num = dp[j];
			}
		}

		dp[i] = past_num + MAP[i];
	}
}

// main
int main() {
	input();
	dp_sol();
	sort(dp, dp + N, greater<>());
	cout << dp[0];
}
