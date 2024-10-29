// Programmers 12914번 Level 2. 멀리뛰기
#include <iostream>
#include <string>
#include <vector>

/* dp 문제
현재의 경우의 수 = 2개 적은 수에서 2 더하는 경우 + 1 적은 수 에서 1 더하는 경우
또한, 더하다보면 생각보다 수가 커지므로 계속 나머지연산 해줄 것
나머지 + 나머지 = 나머지 (모듈러 연산)*/

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long tmp1 = 1; long long tmp2 = 2;
    
    for (int i = 3; i <= n; i++) {
        answer = (tmp1+tmp2) % 1234567;
        tmp1 = tmp2 % 1234567;
        tmp2 = answer % 1234567;
    }
    
    if (n==1) answer = tmp1;
    else if (n==2) answer = tmp2;
    
    return answer%1234567;
}
