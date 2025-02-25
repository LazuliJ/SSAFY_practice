#include <iostream>
#include <vector>

using namespace std;

// 백준 1043번 거짓말
// Union-Find
// 특정 조건을 만족시키는 노드를 표기할 때 -1보다는 (인덱스 범위 오류)의 가능성 존재
// 0이 낫다.

int N, M, FP;
int par[51] = { 0, };
vector<vector<int>> party_list;

void init() {
	for (int i = 0; i < 51; i++) {
		par[i] = i;
	}
}

void input() {
	cin >> N >> M;
	cin >> FP;
	for (int f = 0; f < FP; f++) {
		int fnum;
		cin >> fnum;
		par[fnum] = 0;
	}
}

int Find(int num) {
	if (par[num] == num) return par[num];
	return par[num] = Find(par[num]);
}

void Union(int a, int b) {
	int par_a = Find(a);
	int par_b = Find(b);

	par[max(par_a, par_b)] = min(par_a, par_b);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	input();
	int ans = M;
	for (int m = 0; m < M; m++) {
		int num, cmp;
		vector<int> party;
		cin >> num >> cmp;
		party.push_back(cmp);
		for (int n = 1; n < num; n++) {
			int num_n;
			cin >> num_n;
			Union(cmp, num_n);
			party.push_back(num_n);
		}
		party_list.push_back(party);
	}

	for (int m = 0; m < M; m++) {
		for (int pm = 0; pm < party_list[m].size(); pm++) {
			if (Find(par[party_list[m][pm]]) == 0) {
				ans--;
				break;
			}
		}
	}
	cout << ans;
}
