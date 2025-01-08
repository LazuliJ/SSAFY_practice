#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 15486번 퇴사 (2) - DP

int N;
vector<pair<int, int>> sch;
vector<ll> dp;
ll ans = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		sch.push_back(make_pair(a, b));
		dp.push_back(0);
	}
	sch.push_back(make_pair(0,0));
	dp.push_back(0);
}

// 만약 실행하지 않는다면 이전의 값을 불러와야 한다.
// (상담하지 않는다고 해서 이전에 벌어놓았던 수당이 사라지는 것이 아니기 때문이다.)

void cal_dp() {
	for (int i = 0; i <= N; i++) {
		if (i != 0) dp[i] = max(dp[i], dp[i - 1]);
		if (sch[i].first + i > N) continue;
		dp[sch[i].first + i] = max(dp[sch[i].first + i], dp[i] + sch[i].second);
	}
}

void max_dp() {
	for (int i = 0; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
}

int main() {
	input();
	cal_dp();
	max_dp();
	cout << ans;
}
