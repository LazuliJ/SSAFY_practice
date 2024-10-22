// 백준 30802번 웰컴 키트

#include <iostream>

using namespace std;

int N, T, P;
int TS[6];
int Ts, Pts, Ps;

void input() {
	cin >> N;
	cin >> TS[0] >> TS[1] >> TS[2] >> TS[3] >> TS[4] >> TS[5];
	cin >> T >> P;
}

int main() {
	input();
	for (int i = 0; i < 6; i++) {
		if (TS[i] % T == 0) {
			Ts += (TS[i] / T);
		}
		else {
			Ts += (TS[i] / T + 1);
		}
	}
	Pts = N / P;
	Ps = N % P;
	
	cout << Ts << endl;
	cout << Pts << " " << Ps;
}
