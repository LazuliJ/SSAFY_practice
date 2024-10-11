// Level 1. 12932번 자연수 뒤집어 배열로 만들기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string N = to_string(n);
    for(int i = N.length()-1; i >=0; i--) {
        // 문자 1개 char형 int(char)-'0'를 이용해서 int
        answer.push_back(int(N[i])-'0');
    }
    return answer;
}
