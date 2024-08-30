// SWEA 5658. 보물상자 비밀번호

#include <iostream>
#include <queue>

using namespace std;

int T;

int main() {
	cin >> T;
	int N, K;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		queue<char> strc; // 입력받은 전체 문자열
		priority_queue<int> ansq;
		for (int i = 0; i < N; i++) {
			char tmp;
			cin >> tmp;
			strc.push(tmp);
		}
		for (int i = 0; i < N / 4; i++) {
			for (int j = 0; j < 4; j++) {
				int k = 0; int num_tmp = 0;
				while (k < N / 4) {
					// 16진수 정수로 변환 
					num_tmp *= 16;
					char ctmp = strc.front(); strc.pop();
					if (int(ctmp) >= int('A')) {
						num_tmp += (int(ctmp) - int('A') + 10);
					}
					else {
						num_tmp += (int(ctmp) - int('0'));
					}
					strc.push(ctmp);
					k++;
				}
				// 후 priority queue에 넣기
				ansq.push(num_tmp);
			}
			// 다른 조합 시도
			char ctmp = strc.front(); strc.pop(); strc.push(ctmp);
		}
		int scores = 1;
		while (true) {
			if (scores == K) {
				cout << "#" << t << " " << ansq.top() << endl; break;
			}
			else {
				int anstmp = ansq.top(); ansq.pop();
				if (anstmp != ansq.top()) scores++;
			}
		}
	}
	
}
