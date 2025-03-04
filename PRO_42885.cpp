#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 42885 - 그리디(greedy)

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int end_p = people.size()-1;
    sort(people.begin(), people.end(), greater<>());
    for (int i = 0; i < people.size(); i++) {
        if (i > end_p) break;
        if (people[i]+people[end_p] <= limit) {
            answer++;
            end_p--;
        }
        else answer++;
    }
    return answer;
}
