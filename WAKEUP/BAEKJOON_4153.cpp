// BAEKJOON 4153 직각삼각형
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a[3]; // 길이 배열 (0이 가장 큼)
	while (true) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3, greater<>());
		// 입력이 끝남
		if (a[0] == 0 and a[1] == 0 and a[0] == 0)
			break;
		// 직각삼각형
		if (a[0] * a[0] == a[1] * a[1] + a[2] * a[2])
			printf("right\n");
		// 아닐때
		else
			printf("wrong\n");
	}
}
