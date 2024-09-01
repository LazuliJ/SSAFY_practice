// 백준 2929번 머신 코드

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;
	str += '0';
	int cnt = 0, ans = 0;
	for (int i = 0; i < str.length()-1; i++) {
		if (str[i] >= 'A' and str[i] <= 'Z') {
			// 나머지 0 일때 0 1일 떄 3 2일때 2 3일 때 1
			if (cnt % 4 != 0) {
				ans += (4 - (cnt%4));
			}
			cnt = 0;
		}
		cnt++;
	}
	cout << ans;
}
