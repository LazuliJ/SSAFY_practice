// Programmers Level 2. 12980번 점프와 순간 이동
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;
    
    // 숫자를 2로 나누어 나머지가 1일 때, 점프
    // 나눈 값이 1이면 점프
    while (n != 1) {
        if (n%2==1) {
            ans++;
            n=(n-1)/2;
        } else {
            n/=2;
        }
    }
    return ans;
}
