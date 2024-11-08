#include <iostream>
#include <algorithm>

using namespace std;

/************************/
int N, M;
int MAP[50][50] = { 0, }; // 원본 MAP

int HOUSE[100][2]; // 집들의 좌표
int h_pointer = 0; // 집의 총 개수

int CHOUSE[13][2]; // 치킨집들의 좌표
int c_pointer = 0; // 치킨집의 총 개수

int CAL_ROAD[100][13]; // 치킨집과 집의 최소거리
int road[13] = { 0, }; // 이 치킨집이 열려있는지 여부 체크
int ans = 10000000; // 최종 정답
/************************/

// 배열 초기화
void init() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 2; j++) {
			HOUSE[i][j] = -1;
		}
	}

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 2; j++) {
			CHOUSE[i][j] = -1;
		}
	}
}

// 입력
void input() {
	cin >> N >> M;
  // 집 / 치킨집의 좌표를 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				HOUSE[h_pointer][0] = i;
				HOUSE[h_pointer][1] = j;
				h_pointer++;
			}
			else if (MAP[i][j] == 2) {
				CHOUSE[c_pointer][0] = i;
				CHOUSE[c_pointer][1] = j;
				c_pointer++;
			}
		}
	}

  // 집과 치킨집 사이의 거리들 연산
	for (int i = 0; i < h_pointer; i++) {
		for (int j = 0; j < c_pointer; j++) {
			CAL_ROAD[i][j] = abs(HOUSE[i][0] - CHOUSE[j][0]) + abs(HOUSE[i][1] - CHOUSE[j][1]);
		}
	}
}

// DFS로 최소 구하기 (백트래킹)
void DFS(int depth, int start) {
	if (depth == M) {
		int tmp_ans = 0;
		for (int i = 0; i < h_pointer; i++) {
			int tmp = 2500;
			for (int j = 0; j < 13; j++) {
				if (road[j] == 1) {
					tmp = min(CAL_ROAD[i][j], tmp);
				}
			}
			tmp_ans += tmp;
			if (tmp_ans > ans) return; // 현재 점수보다 계산 중인 점수가 더 큼
		}
		ans = min(tmp_ans, ans);
		return;
	}
	for (int i = start; i < c_pointer; i++) {
		if (c_pointer - i < M - depth) continue; // 너무 많이 폐점함.
		road[i] = 1;
		DFS(depth + 1, i + 1);
		road[i] = 0;
	}
}

// main
int main() {
	init();
	input();
	DFS(0, 0);
	cout << ans;
}
