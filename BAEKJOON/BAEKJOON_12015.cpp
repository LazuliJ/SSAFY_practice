#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll N;
vector<ll> arr;

// 12015번 가장 긴 증가하는 부분 수열2
// 이분탐색 LIS
// binary search 조건 때문에 mid == 0일 때 탈출 가능하다면 start = 0 end = 1 일때 
// 반드시 mid == 0으로 실제 조건 만족 여부에 상관없이 탈출하므로 이에 유의
// 이 문제를 해결하기 위해 vector에 가장 작은 수(0)을 넣어서 초기화하고 최종 답안 -1한다.

void binary_search(ll num) {
	ll start = 0; ll end = arr.size()-1;
	while (true) {
		ll mid = (start + end) / 2;
		if (arr[mid] >= num and arr[mid - 1] < num) {
			arr[mid] = num;
			break;
		}
		else if (arr[mid] > num) end = mid - 1;
		else start = mid+1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr.push_back(0);
	for (ll n = 0; n < N; n++) {
		ll num;
		cin >> num;
		if (arr.size() == 0) arr.push_back(num);
		if (arr.back() < num) arr.push_back(num);
		else if (arr.back() == num) continue;
		else {
			binary_search(num);
		}
	}
	cout << arr.size()-1;
	//for (int i = 0; i < arr.size(); i++) {
		//cout << arr[i] << " ";
	//}
}
