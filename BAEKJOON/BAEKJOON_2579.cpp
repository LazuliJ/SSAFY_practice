#include <iostream>
#include <algorithm>

// 백준 2579번 - 계단 오르기
/*
DP = 분할정복+저장의 성격을 띈 알고리즘
 = 즉, 1. 기록하면서 풀이할 수 있어야 함.
 = 2. 작은 문제들로 나누어 풀이할 수 있어야 하며, (점화식)
 이 문제의 풀이 방식이 모든 작은 문제들에 대해 동일해야함.

 구현 방법) 
 1. Top-down (큰 숫자 -> 작은 숫자) -> 재귀
 2. Bottom-up (작은 숫자 -> 큰 숫자) -> 반복

 이 중에서도 이 문제는 Bottom-up의 방식을 이용해서 풀이됨.

 특이한 조건 중, 3개의 계단을 동시에 밟아서는 안된다는 조건이 있음
 -> 이 조건은 
 N-3까지의 합 + N-1의 값 + N의 값
 N-2까지의 합 + N의 값
 을 비교함으로서 해결할 수 있다. (N-1과 비교시 조건을 해결할 수 X)
*/

using namespace std;

/*********************/
int N;
int MAP[301] = { 0, }; // 배열1. 값을 저장
int SUM[301] = { 0, }; // 배열2. N까지의 합 최대를 구함.
/*********************/

//input
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> MAP[i];
	}
 }

//bottom-up 방식 DP
void DP() {
	SUM[1] = MAP[1];
	SUM[2] = MAP[1]+MAP[2];

	// 3번의 값이 자동으로 구하기 애매하므로 수동으로 구하기
	SUM[3] = max(MAP[1] + MAP[3], MAP[2] + MAP[3]);
	for (int i = 4; i <= N; i++) {
		SUM[i] = max(SUM[i - 3] + MAP[i - 1] + MAP[i], SUM[i - 2] + MAP[i]);
	}
}

//main
int main() {
	input();
	DP();
	cout << SUM[N];
}
