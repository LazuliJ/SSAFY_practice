// Level 1. 12916번 문자열 내 p와 y의 개수
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int ans[2] = {0, 0};

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' or s[i] == 'P') ans[0]++;
        else if (s[i] == 'y' or s[i] == 'Y') ans[1]++;
    }
    
    if (ans[0]!=ans[1]) answer=false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
