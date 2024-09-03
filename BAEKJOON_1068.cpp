// 백준 1068번

/*
나는 이 문제를 두 단계로 나누어 접근했는데,
1. 삭제될 노드 알아보기
2. 어떤 노드의 부모인지 알아보기이다.

그 전 쉽게 알 수 없는 2가지의 예외가 있는데.
1. 시작점이 0임이 보장되지 않음
2. 꼭 2진트리가 아닐 수 있음.
이 점을 주의해도, start_node를 처리하는데 있어 어려움이 있을 수 있다.
1. start_node를 삭제하는 경우
2. start_node만 남는 경우
이 2가지 경우를 고려해주어야 한다.

1번은 직접 start_node를 삭제했는지 알아보아야 하고, (즉, start_node=del_node)
2번은 당연하게도 삭제하지 않은 start노드가 누군가의 부모인지 알아야 한다.

솔직히 반례 안봤으면 못풀었을 것 같다.
*/
#include <iostream>
#include <cstring>

using namespace std;

int N, del_node;
int start_node; // 시작 노드가 0임이 보장되지 않음에 주의!!
int parent[50] = { 0, };
int MAP[50][50] = { 0, };
int visited[50] = { 0, };
int ans = 0;

void DFS(int node) {
	if (MAP[node][0] == -1) return;
	for (int i = 0; i < 50; i++) {
		if (MAP[node][i] == -1) break;
		parent[MAP[node][i]] = -1;
		DFS(MAP[node][i]);
	}
	
}

int main() {
	// input
	cin >> N;
	// parent는 이어져 있는 노드
	memset(MAP, -1, sizeof(MAP));
	for (int i = 0; i < N; i++) {
		cin >> parent[i];
		if (parent[i] == -1) {
			start_node = i;
			continue;
		}
		for (int j = 0; j < 50; j++) {
			if (MAP[parent[i]][j] == -1) {
				MAP[parent[i]][j] = i;
				break;
			}
		}
	}
	// 삭제되는 노드와 이어져 있으면 모두 -1 = 연결을 끊는다.
	cin >> del_node;
	parent[del_node] = -1;
	DFS(del_node);
	// 상위 노드와 연결이 없는 노드외에는 연결되어 있는 상위 노드는 모두 visited 처리한다.
	for (int i = 0; i < N; i++) {
		if (parent[i] == -1) continue;
		else visited[parent[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (parent[i] != -1 and visited[i] == 0) ans++;
	}
	if (start_node != del_node and visited[start_node] == 0) ans++;
	cout << ans;
}
