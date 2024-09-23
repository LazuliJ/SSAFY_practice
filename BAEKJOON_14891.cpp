// 백준 14891번 톱니바퀴
#include <iostream>

using namespace std;

int ans = 0;
int K = 0;
char gears[5][8] = { 0, };
int pters[5] = { 0, };

// 포인터 각각으로 12시 방향이 어느 기어인지 표기
// 반시계로 회전하면 포인터는 +1이 됨을 주의(오른쪽기어가 왼쪽으로 이동)

void input() {
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> gears[i][j];
		}
	}
	cin >> K;
}

void do_round()
{
	int num, dir;
	cin >> num >> dir;
	
	int dirs[5] = { 0, };
	dirs[num] = dir * -1;

	// 왼쪽 기어들 돌아가는 것 확인
	int n = num-1;
	while (n > 0) {
		if (gears[n + 1][(pters[n + 1]+6)%8] == gears[n][(pters[n]+2)%8]) {
			break;
		}
		dirs[n] = -1 * dirs[n+1];
		n--;
	}

	// 오른쪽 기어들 돌아가는 것 확인
	n = num + 1;
	while (n < 5) {
		if (gears[n - 1][(pters[n - 1] + 2) % 8] == gears[n][(pters[n] + 6) % 8]) {
			break;
		}
		dirs[n] = -1 * dirs[n-1];
		n++;
	}

	// 결과 반영
	for (int i = 0; i < 5; i++) {
		pters[i] = (pters[i] + dirs[i] + 8) % 8;
	}
}

int main() {
	input();
	for (int i = 0; i < K; i++) {
		do_round();
	}
	int sc = 1;
	for (int i = 1; i < 5; i++) {
		ans += (sc * (int(gears[i][pters[i]]) - int('0')));
		sc *= 2;
	}
	cout << ans;
}
