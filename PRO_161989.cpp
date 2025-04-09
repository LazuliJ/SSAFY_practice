#include <string>
#include <vector>

using namespace std;

// 프로그래머스 161989 덧칠하기
// Greedy

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int st_p = section[0];
    for (auto s: section) {
        if(s-st_p >= m) {
            st_p = s;
            answer++;
        }
    }
    return answer;
}
