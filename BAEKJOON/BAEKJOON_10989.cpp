// 백준 10989번 수 정렬하기3

#include <iostream>

using namespace std;

// 많은 양의 숫자(문자)를 실제로 저장하지 않고 빠르게 정렬하는 법 = DAT

/***********************/
int N;
int DAT[10001] = { 0, };
/***********************/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		DAT[tmp]++;
	}
	
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < DAT[i]; j++) {
			cout << i << "\n";
		}
	}
}
