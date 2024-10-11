// Level 1. 12933번 정수 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string N = to_string(n);
    // 문자열도 벡터처럼 정렬이 가능하다.
    sort(N.begin(), N.end(), greater<>());
    // long long형태로 바꾸기 stoll(string) = long long
    answer = stoll(N);
    
    return answer;
}
