// Programmers Level 2. 12973번 짝지어 제거하기

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*괄호 쌓기와 비슷한 stack 문제*/

int solution(string s)
{
    int answer = -1;
    vector<char> stack;
    
    for (int i = 0; i < s.length(); i++) {
        if (i!=0 and stack.back() == s[i]) {
            stack.pop_back();
        }
        else {
            stack.push_back(s[i]);
        }
    }
    
    if (stack.empty()) answer = 1;
    else answer = 0;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
