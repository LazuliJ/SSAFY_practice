#include <iostream>
#include <algorithm>

using namespace std;

// 백준 14719번 빗물 - 시뮬레이션

int H, W;
int ans = 0; // 빗물의 총량
int arr[501] = { 0, };
int max_arr[501]{ 0, };

// input
void input() {
	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}
}

// 현재 높이의 공간을 찾음
void find(int height) {
	for (int i = 0; i < W; i++) {
		if (arr[i] == height) {
			max_arr[i] = max(max_arr[i], height);
		}
	}
}

// 어떤 높이 이상으로 둘러쌓인 공간을 찾아서 빗물을 채움
void count(int max_height) {
	int idx = -1;
	for (int i = 0; i < W; i++) {
		if (max_arr[i] >= max_height) {
			if (idx == -1) {
				idx = i;
			}
			else {
				for (int j = idx; j <= i; j++) {
					max_arr[j] = max(max_arr[j], max_height);
				}
				idx = i;
			}
		}
	}
}

int main() {
	cin >> H >> W;
	input();

	for (int i = H; i >= 1; i--) {
		find(i);
		count(i);
	}

	for (int i = 0; i < W; i++) {
		ans += (max_arr[i] - arr[i]);
	}

	cout << ans;
}
