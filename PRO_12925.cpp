// Level 1. 12925번 문자열을 정수로 바꾸기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp = "";
    // c++ string 함수: isdigit(string), 만약 0이면 숫자가 아니고, 숫자라면 그 숫자가 나옴(따라서 0이 올때는 주의)
    if (isdigit(s[0]) == 0) {
        for (int i = 1; i < s.length(); i++) {
            tmp += s[i];
        }
        answer = stoi(tmp);
        if (s[0] == '-') {   
            answer *= -1;
        }
    }
    else {
        answer = stoi(s);
    }
    
    return answer;
}
