#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 32945번 극한직업 - 영양사 선생님 
// 그리디, 정렬, 스위핑

int N; // 학생수
int ans = 0; // 정답(혼잡도)
vector<ll> student; // 학생들의 식사시간
vector<pair<ll, int>> eat_time; // 식사시작을 고려한 식사시간

void input() {
    cin >> N;
    for (int n = 0; n < N; n++) {
        ll t;
        cin >> t;
        // 기본적으로 sort는 작은수부터 정렬 -> 큰 수부터 역으로 정렬하기 위해서
        student.push_back(-1 * t);
    }
}

void act() {
    sort(student.begin(), student.end());
    for (int n = 0; n < N; n++) {
        ll time = 1+n+(-1)*student[n];
        eat_time.push_back({(n+1), 1});
        eat_time.push_back({time, -1});
    }
    sort(eat_time.begin(), eat_time.end());
}

void count_max() {
    int tmp = 0;
    for (int n = 0; n < 2*N; n++) {
        tmp += eat_time[n].second;
        //cout << tmp;
        ans = max(tmp, ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    act();
    count_max();
    cout << ans;
}
