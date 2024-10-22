// 백준 14890번 경사로
#include <iostream>

using namespace std;

int N, L;
int MAP[100][100] = { 0, };
int ans = 0;

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

void count_Y() {
	for (int i = 0; i < N; i++) {
		int num = MAP[i][0]; int cnt = 1;
		int flag = 1;
		for (int j = 1; j < N; j++) {
			// 같다면
			if (num == MAP[i][j]) {
				cnt++;
				continue;
			}

			// 만약 다음수가 크다면
			// 1 차이가 아닐 때
			else if (num + 1 == MAP[i][j]) {
				if (cnt >= L) {
					num = MAP[i][j];
					cnt = 1;
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
			// 다음수가 작다면
			else if (num - 1 == MAP[i][j]) {
				if (cnt < 0) {
					flag = 0;
					break;
				}
				else {
					num = MAP[i][j];
					cnt = -(L - 1);
					continue;
				}
			}
			// 1 차이가 아닐 때
			else {
				flag = 0;
				break;
			}
		}
		if (flag == 0 or cnt < 0) {
			continue;
		}
		else {
			ans++;
		}
	}
}

void count_X() {
	for (int i = 0; i < N; i++) {
		int num = MAP[0][i]; int cnt = 1;
		int flag = 1;
		for (int j = 1; j < N; j++) {
			// 같다면
			if (num == MAP[j][i]) {
				cnt++;
				continue;
			}

			// 만약 다음수가 크다면
			// 1 차이가 아닐 때
			else if (num + 1 == MAP[j][i]) {
				if (cnt >= L) {
					num = MAP[j][i];
					cnt = 1;
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
			// 다음수가 작다면
			else if (num - 1 == MAP[j][i]) {
				if (cnt < 0) {
					flag = 0;
					break;
				}
				else {
					num = MAP[j][i];
					cnt = -(L - 1);
					continue;
				}
			}
			// 1 차이가 아닐 때
			else {
				flag = 0;
				break;
			}
		}
		if (flag == 0 or cnt < 0) {
			continue;
		}
		else {
			ans++;
		}
	}
}

int main() {
	input();
	count_Y();
	count_X();
	cout << ans;
}
