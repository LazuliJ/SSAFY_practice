#include <iostream>
#include <deque>

using namespace std;

// 백준 2606번 바이러스 - Linked List
// 순서를 보장하지 않는 Linked List

struct NODE {
	int num;
	NODE* next;
};

NODE HEAD[101]; // 1번, 2번, 3번 컴퓨터...
bool if_virus[101]; // 바이러스 감염 여부
NODE POOL[101 * 101]; // 할당할 수 있는 메모리 모음
int pcnt = 0; // 중복 할당 방지

int computer_numbers; // 컴퓨터 갯수
int connectivity; // 연결 갯수

// input
void input() {
	cin >> computer_numbers;
	cin >> connectivity;
}

// v번 컴퓨터에 연결된 u번 컴퓨터
void connect(int u, int v) {
	NODE *now = &POOL[pcnt++];
	now->num = u;
	
	now->next = HEAD[v].next;
	HEAD[v].next = now;
}

// BFS를 통해 감염된 컴퓨터를 탐색
int BFS() {
	deque<int> dq;
	int ans = 0;
	dq.push_back(1);
	if_virus[1] = true;

	while (!dq.empty()) {
		int now_num = dq.front(); dq.pop_front();
		if (HEAD[now_num].next == NULL) continue;
		NODE *now = HEAD[now_num].next;
		while (true) {
			int cur = now->num;
			if (if_virus[cur] == false) {
				// cout << cur; // test code
				if_virus[cur] = true;
				dq.push_back(cur);
				ans++;
			}
			if (now->next == NULL)break;
			now = now->next;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	for (int cnty = 0; cnty < connectivity; cnty++) {
		int u, v;
		cin >> u >> v;
		connect(u, v);
		connect(v, u);
	}

	cout << BFS();

}
