// 12937번 짝수와 홀수
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    // num이 정수 범위라는 것은 음수일 수도 있다는 것이다.
    if (num % 2 == 1 or num % 2 == -1) {
        answer = "Odd";
    } 
    else answer = "Even";
    return answer;
}
