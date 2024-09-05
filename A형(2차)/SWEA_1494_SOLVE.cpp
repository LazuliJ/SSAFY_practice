// SWEA 사랑의 카운슬러
/*
1. 문제 이해하기
가만히 있는 지렁이들의 벡터합,
- 움직이는 지렁이들의 벡터합
최소값을 return;

2. 구현~!
 - 기저쪽에서 연산 처리
 - 매개변수로 값을 넘겨가면서 처리 V

 문제는 심플하게 구성
 입력 벡터 제곱 연산처리
 100, 000 ^ 2
 10^10 int로는 정답이 나오지 않겠구나~!
 long long으로 하자~!

 모든 지렁이들을 매칭 시켰을 때, 움직인 벡터들의 합
*/
#include <iostream>

using namespace std;

struct Coord {
	int y;
	int x;
};
Coord coords[21];
int N;
int visited[21];
typedef long long ll;
ll ans;
int Plus; // 움직이지 않는 지렁이들의 개수를 카운팅
int Minus; // 움직이는 지렁이들의 개수를 카운팅 N/2

void init() {
	memset(visited, 0, sizeof(visited));
	Plus = 1;
	Minus = 0;
	ans = 999999999999;
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> coords[i].x >> coords[i].y;
	}
}
//어떤것을 매개변수로 세팅할 것인가?
//1.now번째, 
void dfs(int now, ll sumX, ll sumY) {
	//기저 조건
	if (Plus == N / 2 && Minus == N / 2) {
		ll ret = sumX * sumX + sumY * sumY;
		if (ans > ret) ans = ret;
		return;
	}

	//움직이지 않는 지렁이들의 벡터합을 구한다.
	if (N / 2 > Plus) {
		Plus += 1;
		dfs(now + 1, sumX + coords[now + 1].x, sumY + coords[now + 1].y);
		Plus -= 1;
	}
	//움직이는 지렁이들의 벡터합을 구한다.
	if (N / 2 > Minus) {
		Minus += 1;
		dfs(now + 1, sumX - coords[now + 1].x, sumY - coords[now + 1].y);
		Minus -= 1;
	}
	return;
}
void solution() {
	dfs(0, coords[0].x, coords[0].y);
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solution();
		cout << "#" << tc << " " << ans << endl;
	} 
}
