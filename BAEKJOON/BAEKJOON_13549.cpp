#include <iostream>
#include <deque>

using namespace std;
typedef long long ll;

// 백준 13549번 숨바꼭질 3 - BFS

ll N, K;
deque<ll> cur_pl;
ll cur_ti[100001] = { 0, };

void input() {
	cin >> N >> K;
	cur_pl.push_back(N);
	cur_ti[N] = 1;
}

void BFS() {
	while (!cur_pl.empty()) {
		ll cur = cur_pl.front(); cur_pl.pop_front();
		ll tmp_cur[2] = { cur - 1, cur + 1};
		// 여기서 K에 대해서 체크하면 안되는 이유가 K가 N보다 크지 않을 수 있기 때문에
		for (ll i = cur*2; i <= 100000; i *= 2) {
			if (cur == 0) break;
			if (i < 0 or i > 100000) continue;
			if (cur_ti[i] != 0) continue;
			cur_ti[i] = cur_ti[cur];
			cur_pl.push_back(i);
		}
		if (cur_ti[K] != 0) break;

		for (int i = 0; i < 2; i++) {
			if (tmp_cur[i] < 0 or tmp_cur[i] > 100000) continue;
			if (cur_ti[tmp_cur[i]] != 0) continue;
			cur_ti[tmp_cur[i]] = cur_ti[cur] + 1;
			cur_pl.push_back(tmp_cur[i]);
		}
		if (cur_ti[K] != 0) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	BFS();

	cout << cur_ti[K]-1;
}
