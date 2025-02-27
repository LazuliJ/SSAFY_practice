#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

// 백준 18110번 solved.ac

int n;
int non;
deque<int> dq;

int main() {
	cin >> n;
	non = round(float(n * 0.15));
	float ans = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		dq.push_back(num);
	}
	sort(dq.begin(), dq.end());
	for (int i = 0; i < non; i++) {
		dq.pop_front();
		dq.pop_back();
	}
	while (!dq.empty()) {
		ans += dq.front();
		dq.pop_front();
	}
	if (n != 0) cout << round(ans / (n - 2 * non));
	else cout << 0; // "아무 의견도 없다면 난이도는 0으로 결정한다."
}
