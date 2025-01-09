#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// 백준 2748번 피보나치 수2 - 기본적 DP

int n;
vector<ll> pibo;

void input() {
	cin >> n;
	pibo.push_back(0);
	pibo.push_back(1);
}

int main() {
	input();
	while (pibo.size() != n+1) {
		pibo.push_back(pibo[pibo.size() - 1] + pibo[pibo.size() - 2]);
	}
	cout << pibo.back();
}
