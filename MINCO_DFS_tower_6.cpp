// 민코딩 DFS의 탑 6번

#include <iostream>
#include <string>

using namespace std;

string target; // 통과해야 하는 문자열
string tars[2]; // 악마의 다리, 천사의 다리
int ans = 0; // 가지수

void DFS(int cur, int leng, int mode) {
	if (cur == target.length()) {
		ans++;
		return;
	}
	if (leng == tars[mode].length()) {
		return;
	}

	DFS(cur, leng + 1, mode);
	if (tars[mode][leng] == target[cur]) {
		if (mode == 0) mode = 1;
		else mode = 0;
		DFS(cur + 1, leng + 1, mode);
	}
}

int main() {
	cin >> target;
	cin >> tars[0]; cin >> tars[1];
	DFS(0, 0, 0);
	DFS(0, 0, 1);
	cout << ans;
}
