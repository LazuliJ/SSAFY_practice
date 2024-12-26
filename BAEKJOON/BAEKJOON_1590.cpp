#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 1590번 캠프가는 영식 - 이분탐색 연습 

int N, T;
vector<ll> times;

void input() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int S, I, C;
        cin >> S >> I >> C;
        for (int j = 0; j < C; j++) {
            times.push_back(S+I*j);
        }
    }
    sort(times.begin(), times.end());
}

int st, ed, mid;
ll ans = -1;
void binary_search() {
    st = 0; 
    ed = times.size()-1;

    while (st <= ed) {
        mid = (st + ed) / 2;
        // times가 처음값보다 작을 때 처리 잘하기
        if (times[mid] >= T and (mid == 0 or times[mid-1] < T)) {
            ans = times[mid] - T;
            break;
        }
        // T > times[mid] 이렇게 쓰는게 더 직관적일 듯
        else if (times[mid] < T) {
            st = mid + 1;
        }
        else {
            ed = mid - 1;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    binary_search();
    cout << ans;
}
