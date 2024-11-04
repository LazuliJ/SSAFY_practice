// 백준 1676번 팩토리얼 0의 개수
#include <iostream>
#include <algorithm>

using namespace std;

// 기본 아이디어: 2와 5의 개수를 세어 작은 것이 정답 (10을 만드려면 1개씩 필요)

/*********************/
int N;
int ans;
int li[2] = { 0, };
/*********************/

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num = i;
		while (num % 2 == 0) {
			li[0]++;
			num /= 2;
		}
		while (num % 5 == 0) {
			li[1]++;
			num /= 5;
		}
	}
	ans = min(li[0], li[1]);
	cout << ans;
}
