// 17496 스타후르츠

#include <iostream>
using namespace std;

int N, T, C, P;

int main() {
	cin >> N >> T >> C >> P;
	long long money = ((N - 1) / T) * C * P;
	cout << money;
}
