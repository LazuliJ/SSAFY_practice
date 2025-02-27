#include <iostream>
#include <string>
#define DIVISION_NUM 1234567891

// 백준 15829번 Hashing
/*
C++ 문법 연습
1. 위의 '1234567891'과 같은 고정된 정수는 #define을 통해 더 쉽게 사용가능
2. 범위 기반 for문
*/

using namespace std;
typedef long long ll;

int L;
string str_L;
ll ans = 0;
ll num = 1;

int main() {
	cin >> L;
	cin >> str_L;

	for (auto l : str_L) {
		ans += ((int(l) + 1 - int('a'))*num)%DIVISION_NUM;
		num *= 31;
		num %= DIVISION_NUM;
		ans %= DIVISION_NUM;
	}
	cout << ans;
}
