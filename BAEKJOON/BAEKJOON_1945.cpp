#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<double, int> pr;

// 백준 1945 직사각형 - 스위핑
/*
기울기의 최대 ~ 최소에서 직사각형이 존재함을 이용한다.
모든 직사각형의 최대/최소 기울기를 구해서 최대=1, 최소=-1로 계산한다.
그 후 기울기의 크기 순으로 정렬해서 +-1을 계산한다.

만약 겹치면 기울기를 세는 쪽으로 한다.
*/

int N;
vector<pr> vec;
int max_ans = 0, ans = 0;

bool cmp(pr pr1, pr pr2) {
	if (pr1.first > pr2.first) return true;
	if (pr1.first < pr2.first) return false;

	// 어떤 사각형의 시작점과 끝점이 겹치면 시작점부터 처리한다.(끝점도 사각형의 일부)
	if (pr1.second > pr2.second) return true;
	if (pr1.second < pr2.second) return false;

	return false;
}

void input() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		double xbl, ybl, xtr, ytr;
		cin >> xbl >> ybl >> xtr >> ytr;
		pr p1, p2;
		double p1_tmp = ytr / xbl;
		double p2_tmp = ybl / xtr;
		p1 = make_pair(p1_tmp, 1); p2 = make_pair(p2_tmp, -1);
		vec.push_back(p1);
		vec.push_back(p2);
	}

	sort(vec.begin(), vec.end(), cmp);
}

void is_max() {
	for (int n = 0; n < vec.size(); n++) {
		ans += vec[n].second;
		//cout << vec[n].first << " ";
		max_ans = max(ans, max_ans);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	is_max();
	cout << max_ans;
}
