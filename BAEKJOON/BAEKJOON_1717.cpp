#include <iostream>

using namespace std;

// 백준 1717번 집합의 표현 - Union-Find(Disjoint-Set)

int n, m;
int par[1000001] = { 0, };

void init() {
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
}

int Find(int a) {
	if (par[a] == a) return a;
	return par[a] = Find(par[a]);
}

void Union(int a, int b) {
	int par_a = Find(a);
	int par_b = Find(b);

	par[par_a] = par_b;
}

bool find_if_same(int a, int b) {
	if (Find(a) == Find(b))return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int cal, u, v;
		cin >> cal >> u >> v;
		if (cal == 0) {
			Union(u, v);
		}
		else if (cal == 1) {
			if (find_if_same(u, v) == true) cout << "yes" << "\n";
			else cout << "no" << "\n";
		}
	}
}
