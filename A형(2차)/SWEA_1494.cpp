// SWEA 1494번 사랑의 카운슬러
// 백트래킹

/*
이 문제의 핵심
1. 벡터의 합의 제곱 = y랑 x를 합한 후 답만 제곱
2. 출발은 1마리만 = 반만 뽑은 후 전체합에서 뺀다. (N=20인게 복선이었던 셈.
일반적으로, DFS를 활용하는 문제는 N=8~10정도를 준다.)

적극적으로 백트래킹을 이용해서 전체에서 이럴경우에 return을 하라는 것은 아니고
그냥 절반만 뽑는게 이 문제의 핵심.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int T, N;

int ys[20]; int xs[20];
long long ally = 0; long long allx = 0;
long long ans;

void DFS(int depth, long long ny, long long nx, int last_C) {
	if (depth == (N / 2)) {
		// x1 - x2 + x3 - x4 = x = x1+x3-(x2+x4) = (x1+x2+x3+x4) - 2(x2+x4) = allx - 2(x2+x4)
		long long tmp = (ally - 2 * ny) *(ally - 2 * ny) + (allx - 2 * nx)*(allx - 2 * nx);
		if (ans > tmp) ans = tmp;
		return;
	}

	// DFS할 때 반드시 답을 복구할 것.
	for (int i = last_C; i < N; i++) {
		ny += ys[i];
		nx += xs[i];
		DFS(depth + 1, ny, nx, i + 1);
		ny -= ys[i];
		nx -= xs[i];
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = 1000e8; ally = 0; allx = 0;
		for (int i = 0; i < N; i++) {
			cin >> ys[i] >> xs[i];
			ally += ys[i];
			allx += xs[i];
		}
		DFS(0, 0, 0, 0);
		cout << "#" << t << " " << ans << "\n";
	}
}
