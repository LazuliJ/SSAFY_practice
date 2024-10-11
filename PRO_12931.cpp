// Level 1. 12931번 자릿수 더하기
#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while (n != 0) {
        answer += (n%10);
        n /= 10;
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
