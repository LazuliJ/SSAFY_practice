// SWEA 5658. �������� ��й�ȣ

#include <iostream>
#include <queue>

using namespace std;

int T;

int main() {
	cin >> T;
	int N, K;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		queue<char> strc; // �Է¹��� ��ü ���ڿ�
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
					// 16���� ������ ��ȯ 
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
				// �� priority queue�� �ֱ�
				ansq.push(num_tmp);
			}
			// �ٸ� ���� �õ�
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