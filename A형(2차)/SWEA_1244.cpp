// SWEA 1244 최대 상금
/*
-- 풀이 방법 -- 
1. 최대~ = 그리디? (X)
2. N이 작으니 완탐? (특히 DFS)

교환 + 비교 해야 하므로 stoi를 할 수 있는 string 형식이 가장 적합
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int C, N; // 교환 횟수
string str; // 입력받는 숫자
string ans;
string max_str; // 최댓값
bool flag;
int num[10] = { 0, };

//init and input
void input() {
	cin >> str >> N;
	ans = str;
	max_str = str;
	sort(max_str.begin(), max_str.end(), greater<>());
	flag = false;
}

//같은 숫자가 있나?
bool Twonum(string s) {
	for (int i = 0; i < 10; i++) {
		num[i] = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		num[int(s[i])-int('0')]++;
		if (num[int(s[i])-int('0')] >= 2) return true;
	}
	return false;
}

// DFS
void DFS(int depth) {
	if (str.length() == 1) return;
	// 주어진 횟수 이전 최댓값을 찾았다! -> 단축
	// 문제가 있다. 1번만 교환횟수가 남았을 때 최댓값이면 어떻게 되는가?
	// 만약 같은 수가 있다면 같은 수끼리 교환
	// 다른 수들이라면 그나마 작은 수들끼리 교환
	if (str == max_str) {
		int tmp = N - depth;
		if (tmp % 2 == 0) {
			ans = max_str;
			flag = true;
			return;
		}
		else if (tmp % 2 == 1) {
			if (Twonum(str)) {
				ans = max_str;
				flag = true;
				return;
			}
			else {
				swap(str[str.length() - 1], str[str.length() - 2]);
				ans = str;
				flag = true;
				return;
			}
		}
	}

	// 종료(기본적: 주어진 교환 횟수가 끝나면 종료)
	if (depth == N) {
		if (stoi(ans) < stoi(str)) ans = str;
		return;
	}

	// 기본코드 (두개를 바꾼 후 모든 경우 알아보기)
	for (int i = 0; i < str.length()-1; i++) {
		for (int j = i+1; j < str.length(); j++) {
			swap(str[i], str[j]);
			DFS(depth + 1);
			if (flag == true) return;
			swap(str[i], str[j]);
		}
	}
}

int main() {
	cin >> C;
	for (int c = 1; c <= C; c++) {
		input();
		DFS(0);

		cout << "#" << c << " " << ans << endl;
	}
}
