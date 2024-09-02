// C++ A형 보충 강의
// 보물상자와 NQueen은 이미 강의에서 풀어서
// 원자소멸 시뮬레이션 / 숫자만들기로 대체한다.

// 창용마을 무리의 개수
#include <iostream>

using namespace std;

int parent[101];//parent 세팅 필수~!!
int groupCnt[101];//그룹의 cnt를 관리하는 배열~!!
int N; // N개의 노드
int M; // M개의 쿼리
int ans;

int solution() {
	//쿼리대로 Union을 처리했을 때,
	//그룹의 Node cnt수가 1이상인 그룹의 총개수는 몇개인가?
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (groupCnt[i] >= 1) cnt++;
	}
	return cnt;
}

int Find(int now) {

	if (now == parent[now]) return now;
	return parent[now] = Find(parent[now]); // 경로 압축을 통해 속도를 획기적으로 개선
	
}

int Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	groupCnt[pA] += groupCnt[pB];
	//pA는 pB가 가지고 있었던 그룹의 노드 개수를 더해준다.~!!
	groupCnt[pB] = 0;
	//pB는 합병되고 그룹의 노드 개수는 0으로 세팅~!!
	parent[pB] = pA; // 문제마다 다르다.
}

void input() {
	cin >> N >> M;
	//parent 세팅~!!
	//groupCnt 초기화 필수~!!
	//Query 대로 Union처리~!!
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		input();
		solution();
		cout << "#" << tc << " " << ans << endl;
	}
}
