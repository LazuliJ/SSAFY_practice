#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int N;
priority_queue<ll, vector<ll>, greater<>> pq;

// 백준 1715번 카드 정렬하기
// PQ, 그리디
// 반복해서 더하는 구조이므로 가장 작은걸 뽑는 것이 최선이다.

ll ans = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll n;
        cin >> n;
        pq.push(n);
    }
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += (a+b);
        pq.push(a+b);
    }
    cout << ans;
}
