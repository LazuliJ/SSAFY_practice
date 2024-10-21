// BAEKJOON 15684번 사다리 타기

#include <iostream>
#include <vector>
using namespace std;

int N, M, H;
vector<vector<int>> vec; // {{0, 0, 0, 1}} 0=이 위치에 사다리가 없음
int flag = 0; // flag로 조건 달성 여부 확인

void input() {
	cin >> N >> M >> H;
	for (int n = 0; n <= N; n++) {
		vector<int> v;
		for (int h = 0; h < H; h++) {
			v.push_back(0);
		}
		vec.push_back(v);
	}
	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;
		vec[b][a - 1] = 1;
		vec[b + 1][a - 1] = 1;
	}
}

// 사다리타기의 결과: 1이면 성공, -1이면 실패
bool result() {
	for (int i = 1; i <= N; i++) {
		int res = i; // i: 출발 res: 현재 위치
		for (int j = 0; j < H; j++) {
			if (res != 1 and vec[res][j] == 1 and vec[res - 1][j] == 1) {
				res--;
			}
			else if (res != N and vec[res][j] == 1 and vec[res + 1][j] == 1) {
				res++;
			}
		}
		// res가 출발 위치와 일치하지 않음
         if (res != i) return false;
	}
	// 모든 위치에서 출발과 도착이 동일
	return true;
}

// 사다리를 0부터 3개까지 뽑으면서 알맞는 case가 있는지 검사
void DFS(int depth, int pos) {
	// 원하는 갯수만큼 뽑았음.
  	if (depth == pos) {
		// 조건 만족 // 디버깅 해보면 조건 만족 자체가 안됨.
 		if (result() == true) {
			flag = 1;
			return;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < H; j++) {
			if (vec[i][j] == 1) continue;
			if (i != 1 and vec[i - 1][j] == 0) {
				vec[i][j] = 1;
				vec[i - 1][j] = 1;
				DFS(depth + 1, pos);
				if (flag == 1) return;
				vec[i - 1][j] = 0;
				vec[i][j] = 0;
			}
			if (i != N and vec[i + 1][j] == 0) {
				vec[i][j] = 1;
				vec[i + 1][j] = 1;
				DFS(depth + 1, pos);
				if (flag == 1) return;
				vec[i + 1][j] = 0;
				vec[i][j] = 0;
			}
		}
	}
	return;
}

int main() {
	input();
	int ans = -1;
	for (int i = 0; i <= 3; i++) {
		DFS(0, i);
		if (flag == 1) {
			ans = i;
			break;
		}
	}
	cout << ans;
} 

// 일부 케이스에 대해서 정답 출력 / 아닌 경우 -1 출력
