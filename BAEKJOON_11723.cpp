// 백준 11723번 집합

/*
C++에서의 문자열
1. char형을 cin을 이용해서 받을 때: 공백을 무시하고 붙여서 한줄로 받는다.
2. string 선언 후 cin을 이용해서 받을 때: 공백 전까지의 값을 받는다.
*/

#include <iostream>
#include <string>

using namespace std;

int M;
int S[21] = { 0, };

int main() {
	// 시간단축을 위한 명령어들
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		string ch;
		int n;
		cin >> ch;
		if (ch == "add") {
			cin >> n;
			S[n] = 1;
		}
		else if (ch == "check") {
			cin >> n;
			cout << S[n] << '\n';
		}
		else if (ch == "remove") {
			cin >> n;
			S[n] = 0;
		}
		else if (ch == "toggle") {
			cin >> n;
			if (S[n] == 1) S[n] = 0;
			else S[n] = 1;
		}
		else if (ch == "all") {
			for (int num = 1; num <= 20; num++) {
				S[num] = 1;
			}
		}
		else if (ch == "empty") {
			for (int num = 1; num <= 20; num++) {
				S[num] = 0;
			}
		}
	}
}
