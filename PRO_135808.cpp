// 프로그래머스 - 과일장수 (그리디)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 그리디 문제 - 큰것부터 정렬하고 사과상자를 포함.
// 상자를 다 채워야 하므로.

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int p = 0;
    sort(score.begin(), score.end(), greater<>());
    
    // 다만 처음부터 박스 개수보다 작을 때는 0을 출력해야 함.
    while(p+m-1 < score.size()) {
        answer += (score[p+m-1]*m);
        p+=m;
    }
    
    return answer;
}
