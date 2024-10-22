// Programmers Level 2 12951번 JadenCase 문자열 만들기
#include <string>
#include <vector>

using namespace std;

// 문자의 조건 뿐만 아니라 예시도 꼼꼼히 보고 문제를 풀이할 것. (가끔 문제에 명시적으로 안쓰여있는 조건이 있다.)

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 or s[i-1] == ' ') {
            if (s[i]>= '0' and s[i]<= '9') answer += s[i];
            else if (s[i] >= 'a' and s[i] <= 'z') answer += char(int(s[i])-int('a')+int('A'));
            else answer += s[i];
        }
        else if (s[i] >= 'A' and s[i] <= 'Z') answer += char(int(s[i])-int('A')+int('a'));
        else answer += s[i];
    }
    return answer;
}
