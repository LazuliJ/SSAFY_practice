// 백준 1654번 랜선 자르기
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/************
- 이분 탐색으로 풀고자 했음. << 방법은 맞다.
- 코드 로직 바꿀 때 덜 수정 된 곳이 있었다. (그래서 계속 7%대에서 틀렸다고 나왔음)
-> 그래서 계속 더하다 보니 오버플로우가 일어나 제대로된 값을 내지 못했던 것

- 별개로 숫자가 크다보니 중간에 start_num + end_num하는 부분과
	기본 설정에서 long long 등 자료형 실수가 일어나기 쉬우므로 조심할 것
************/


/*********************************************/
int K, N;
vector<int> vec;
long long ans = 0;
long long start_num = 1; long long end_num = pow(2, 32)-1;
/*********************************************/

// 입력
void input() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
}

int main() {
	// 시간 단축
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();

	// 이분 탐색 코드
	while (true) {
		long long pivot = (start_num + end_num) / 2;
		int cur_num = 0;
		for (int i = 0; i < vec.size(); i++) {
			cur_num += (vec[i] / pivot);
		}
		if (start_num == end_num) {
			if (cur_num >= N) ans = pivot;
			else ans = pivot - 1;
			break;
		}
		if (cur_num >= N) {
			start_num = pivot + 1;
		}
		else {
			end_num = pivot - 1;
		}
	}
	cout << ans;
}
