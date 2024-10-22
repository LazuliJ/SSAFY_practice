// 민코딩 구현의 탑 8번

#include <iostream>

using namespace std;

int N;
int MAP[6][6];
int init_x;
char dir;

int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { 1, -1, 1, -1 };

int main() {
	// init
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			MAP[i][j] = 0;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> init_x >> dir;
		if (init_x == 0) dir = 'R';
		if (init_x == 5) dir = 'L';
		int ny = 5; int nx = init_x; int ndir = 0; int n = 1;
		if (dir == 'R') {
			ndir = 0;
			while (true) {
				if (MAP[ny][nx] == 0 or MAP[ny][nx] > n) MAP[ny][nx] = n;
				n++;
				if (n == 11) break;
				if (ndir == 0 and nx == 5) {
					if (ny == 0 or ny == 5) break;
					ndir = 1;
				}
				else if (ndir == 1 and ny == 0) {
					ndir = 3;
				}
				else if (ndir == 3 and nx == 0) {
					ndir = 2;
				}
				ny += dy[ndir];
				nx += dx[ndir];
			}
		}

		if (dir == 'L') {
			ndir = 1;
			while (true) {
				if (MAP[ny][nx] == 0 or MAP[ny][nx] > n) MAP[ny][nx] = n;
				n++;
				if (n == 11) break;
				if (ndir == 1 and nx == 0) {
					if (ny == 0 or ny == 5) break;
					ndir = 0;
				}
				else if (ndir == 0 and ny == 0) {
					ndir = 2;
				}
				else if (ndir == 2 and nx == 5) {
					ndir = 3;
				}
				ny += dy[ndir];
				nx += dx[ndir];
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (MAP[i][j] == 0) cout << '_';
			else cout << MAP[i][j];
		}
		cout << endl;
	}

}
