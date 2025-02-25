#include <iostream>

using namespace std;
typedef long long ll;

// 백준 2302번 극장 좌석 - DP
// 점화식 O(n) = O(n-1) + O(n-2) <- 여기서 VIP석이 연속으로 붙어있는 경우를 조심할 것

int N, M;
ll pos[41] = { 0, };
ll ans = 1;

void DP() {
	pos[0] = 1;
	pos[1] = 1;
	pos[2] = 2;
	for (int i = 3; i < 41; i++) {
		pos[i] = pos[i - 1] + pos[i - 2];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	DP();
	int last = 1;
	for (int m = 0; m < M+1; m++) {
		int num;
		if (m != M) cin >> num;
		else num = N+1;
		ans *= pos[num - last];
		last = num + 1;
	}
	cout << ans;
}
