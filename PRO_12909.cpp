// Programmers Level 2. 12909번 올바른 괄호
#include<string>
#include <iostream>
#include <vector>

/*Stack을 이용해 괄호 조건이 일치시 pop
아니면 push, 마지막에 vec의 길이가 0이 아니라면 잘못된 괄호*/

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> vec;
    for (int i = 0; i < s.length(); i++) {
        if (i!=0 and s[i] == ')' and vec.back() == '(') { // 0일때는 vec.back()을 확인할 수 없음에 유의
            vec.pop_back();
        } 
        else {
            vec.push_back(s[i]);
        }
    }
    if (vec.size() == 0) answer = true;
    else answer = false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
