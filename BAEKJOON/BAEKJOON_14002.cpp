#include <iostream>
#include <vector>
#include <algorithm>

// 백준 14002번 가장 긴 증가하는 부분 수열4
// LIS 응용
// LIS 개념: 나의 길이 = max(나의 길이, 나보다 작은 애들중 가장 긴 길이 + 1)
// LIS에서 배열을 어떻게 저장하느냐? -> 나보다 작은 애를 참조하면 그 인덱스를 저장
// 끝에 역으로 오면서 인덱스를 따라 출력 가능하다.

using namespace std;

int N;
int max_idx = 0; // 가장 긴 길이의 인덱스 (역으로 출력)
vector<int> arr; // 값
vector<int> child_arr; // 내가 참조한 값의 인덱스
vector<int> length; // 길이

int main() {
	cin >> N;
	// LIS
	for (int n = 0; n < N; n++) {
		int num;
		cin >> num;
		arr.push_back(num);
		child_arr.push_back(-1);
		length.push_back(1);
		for (int m = 0; m < n; m++) {
			if (arr[n] > arr[m]) {
				if (length[n] < length[m] + 1) {
					length[n] = max(length[n], length[m] + 1);
					child_arr[n] = m; // 역추적을 위해 직전 인덱스 저장
				}
			}
		}
		if (length[n] > length[max_idx]) max_idx = n;
	}
	// 값들 역추적
	int idx = max_idx;
	vector<int> max_arr;
	while (1) {
		max_arr.push_back(arr[idx]);
		idx = child_arr[idx];
		if (idx == -1) break;
	}
	// 출력
	cout << length[max_idx] << "\n";
	for (int i = max_arr.size()-1; i >= 0; i--) {
		cout << max_arr[i] << " ";
	}
}
