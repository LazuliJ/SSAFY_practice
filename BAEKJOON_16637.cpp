// 백준 16637번 괄호 추가하기

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N; // 수식의 총 길이 (1-19)
string str; // 입력받은 수식
int visited[10] = { 0, }; // 괄호처리
long long ans = -1*21e10;
queue<int> q;

// init and input
void input() {
	cin >> N;
	cin >> str;
}

long long cal(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

vector<int> nums;
vector<char> opers;

void curr(int depth) {
	// 재귀
	if (depth == N / 2) {
		long long tmp = nums[0];
		/*if (opers.size() == nums.size()) {
			for (int i = 0; i < opers.size(); i++) {
				cout << opers[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < nums.size(); i++) {
				cout << nums[i] << " ";
			}
			cout << endl;
		}*/

		for (int i = 0; i < opers.size(); i++) {
			tmp = cal(opers[i], tmp, nums[i+1]);
		}
		// cout << tmp << " ";
		if (tmp > ans) ans = tmp;
		return;
	}
	// 괄호 추가
	if (depth == 0 or visited[depth - 1] == 0) {
		int last = nums[nums.size()-1];
		nums.pop_back();

		int next = cal(str[2 * depth + 1], int(str[2 * depth]) - int('0'), int(str[2 * depth + 2]) - int('0'));
		visited[depth] = 1;
		nums.push_back(next);
		curr(depth + 1);
		nums.pop_back();
		visited[depth] = 0;

		nums.push_back(last);
	}
	//괄호 미추가
	nums.push_back(int(str[2 * depth + 2]) - int('0'));
	opers.push_back(str[2 * depth + 1]);
	curr(depth + 1);
	opers.pop_back();
	nums.pop_back();
}

int main() {
	input();
	nums.push_back(int(str[0]) - int('0'));
	curr(0);
	cout << ans;
}
