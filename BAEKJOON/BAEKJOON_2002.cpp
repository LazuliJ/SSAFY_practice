#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 백준 2002번 추월
/*
처음 이 문제를 접했을 때는 LIS로 푼다고 생각했음
= 올바른 순서를 찾는다고 생각해서
LIS로 풀이하면 안되는 이유는 단순히 '순서'로 생각했을 때는
'추월 당한 차량'을 배제하는 것이 더 이득일 때가
있기 때문이다.

문제에서는 '추월'한 차량을 세라고 했기 때문에 LIS
가 아니라 그냥 단순히 뒷 차가 내 앞에 왔어야 하는
차가 아니면 된다.
*/

int N;
unordered_map<string, int> MAP;
vector<int> vec;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int n = 0; n < N; n++) {
        string key;
        cin >> key;
        MAP[key] = n;
    }

    for (int n = 0; n < N; n++) {
        string key;
        cin >> key;
        vec.push_back(MAP[key]);
    }

    for (int n = 0; n < N; n++) {
        bool if_right = true;
        for (int m = n+1; m < N; m++) {
            if (vec[m] < vec[n]) {
                if_right = false;
                break;
            }
        }
        if (!if_right) ans++;
    }
    cout << ans;
}
