#include <iostream>

// SWEA 1210번 Ladder1

using namespace std;

/**************************/
int T;
int MAP[100][100] = { 0, };
int st_x = 0, st_y = 99;
/**************************/

// 초기화
void init() {
	st_x = 0; st_y = 99;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			MAP[i][j] = 0;
		}
	}
}

// 입력
void input() {
	cin >> T;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> MAP[i][j];
		}
	}
}

// 출발점 찾기
int init_x() {
	for (int i = 0; i < 100; i++) {
		if (MAP[99][i] == 2) {
			return i;
		}
	}

}

// (역방향) 사다리 찾기
void sol() {
	while (st_y != 0) {
		// 양쪽에 이어지는 사다리가 있는지 확인 
		if (st_x != 0 and MAP[st_y][st_x - 1] == 1) {
			st_x--;
			while (MAP[st_y - 1][st_x] != 1) {
				st_x--;
			}
		}
		else if (st_x != 99 and MAP[st_y][st_x + 1] == 1) {
			st_x++;
			while (MAP[st_y - 1][st_x] != 1) {
				st_x++;
			}
		}
		st_y--;
	}
	return;
}

// main
int main() {
	for (int t = 1; t <= 10; t++) {
		init();
		input();
		st_x = init_x();
		sol();
		cout << "#" << t << " " << st_x << "\n";
	}
}
