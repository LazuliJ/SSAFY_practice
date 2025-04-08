#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 1900번 레슬러
// 그리디, 정렬

int N;
int athl_info[10002][2] = {0,};

struct athl {
    int num;
    int wins = 0;
};

vector<athl> athls;

bool cmp(athl a, athl b) {
    if (a.wins > b.wins) return true;
    if (a.wins < b.wins) return false;

    if (a.num < b.num) return true;
    if (b.num < a.num) return false;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> athl_info[i][0] >> athl_info[i][1];
        athl a;
        a.num = i;
        athls.push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            long long i_power = athl_info[i][0] + athl_info[j][0] * athl_info[i][1];
            long long j_power = athl_info[j][0] + athl_info[i][0] * athl_info[j][1];

            if (i_power > j_power) {
                athls[i-1].wins++;
            }
            else {
                athls[j-1].wins++;
            }
        }
    }
    sort(athls.begin(), athls.end(), cmp);
    for (auto a: athls) cout << a.num << "\n";
}
