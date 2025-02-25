#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 11052번 카드 구매하기 - DP

int N;
ll P[1001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> P[n];
		for (int i = 0; i <= n; i++) {
			int j = n - i;
			P[n] = max(P[n], P[i] + P[j]);
		}
	}
	cout << P[N];
}
