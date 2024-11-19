#include <iostream>
#include <algorithm>

using namespace std;

// 11053번 가장 긴 증가하는 부분 수열 - DP

/*************************/
int len_MAP[1001] = { 0, }; // DP배열 저장
int MAP[1001] = { 0, }; // 일반 숫자 저장

int N; // 수열 크기
/*************************/

// input
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
}

// DP (나보다 작은 수 중 최장 거리 + 1)
void DP() {
	len_MAP[0] = 1;
	for (int i = 1; i < N; i++) {
		int max_num = 0;
		for (int j = 0; j < i; j++) {
			if (MAP[j] < MAP[i] and len_MAP[j] > max_num) {
				max_num = len_MAP[j];
			}
		}
		len_MAP[i] = max_num + 1;
	}
}

// main
int main() {
	input();
	DP();
	sort(len_MAP, len_MAP + N, greater<>());
	cout << len_MAP[0];
}
