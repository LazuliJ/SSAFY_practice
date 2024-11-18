#include <iostream>
#include <algorithm>

using namespace std;

// 백준 1912번 연속합 - dp(LIS)

/******************************/
int n;
long long MAP[100001] = { 0, };
long long lis[100001] = { 0, };
/******************************/

// input
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
	}
}

// dp(LIS)
void dp_lis() {
	lis[0] = MAP[0];
	for (int i = 1; i < n; i++) {
		lis[i] = max(MAP[i], lis[i - 1] + MAP[i]);
	}
	sort(lis, lis + n, greater<>());
}

// main
int main() {
	input();
	dp_lis();
	cout << lis[0];
}
