#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq_big;
priority_queue<int, vector<int>, greater<>> pq_small; 

// 백준 1655번 가운데를 말해요
// pq 2개를 이용해서 풀이하는 문제
// 가운데값만 알면 되니까 큰값들 중 가장 작은 값과 작은값들 중 큰값을 알면된다.

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int n = 0; n < N; n++) {
        int num;
        cin >> num;
        if (pq_big.size() <= pq_small.size()) pq_big.push(num);
        else pq_small.push(num);
        
        if (pq_small.size() != 0 and pq_small.top() < pq_big.top()) {
            int tmp = pq_small.top(); pq_small.pop();
            pq_small.push(pq_big.top()); pq_big.pop();
            pq_big.push(tmp);
        }

        cout << pq_big.top() << "\n";
    }
}
