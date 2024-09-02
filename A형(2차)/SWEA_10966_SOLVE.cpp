#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
string s[1001];
int visited[1001][1001];
int N, M;
struct Node {
	int y;
	int x;
};
queue<Node>q;
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };
int ans;
void init() {
	ans = 0;
	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < 1001; i++)
		s[i].clear();
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	//'W' -> 육지('L')로 이동하는데 최소횟수 기록 처리~!
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s[i][j] == 'W') {
				q.push({ i,j }); //W인 좌표 모두 등록
				visited[i][j] = 0;
			}
		}
	}
}
void bfs() {

	//다음 next찾기 부터 시작~!!
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny >= N || nx >= M || ny < 0 || nx < 0)continue;
			// 예외 처리 조건 생각해보기~!! visited
			// 
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
			//visited 업그레이드 코드
			//맵에서 땅인 모든 좌표에서, 
			//땅에서 물까지 이동하는데 걸리는 최소 이동회수의 총합
			ans += visited[ny][nx];
		}

	}

}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		bfs();
		cout << "#" << tc << " " << ans << "\n";

	}
}
