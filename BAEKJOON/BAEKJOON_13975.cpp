#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

// 백준 13975번 파일 합치기 3
// 1715번이랑 마찬가지로 가장 작은 수를 여러번 더하는게 이득이다.
// PQ

int T;
ll K;

priority_queue<ll, vector<ll>, greater<>> pq;
ll ans = 0;

void init() {
    ans = 0;
    while(!pq.empty()) {
        pq.pop();
    }
}

void input() {
    cin >> K;
    for (int k = 0; k < K; k++) {
        ll num;
        cin >> num;
        pq.push(num);
    }
}

void act() {
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();

        ans += (a+b);
        pq.push(a+b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int t = 0; t < T; t++) {
        init();
        input();

        act();
        cout << ans << "\n";
    }
}
