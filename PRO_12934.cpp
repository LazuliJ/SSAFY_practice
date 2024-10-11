// Level 1. 12934번 정수 제곱근 판별
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long ans = -1;
    // 범위 조심. 어짜피 n크기 때문에 break되니 오버플로우 안되는 선에서 넉넉하게 잡을 것
    for (long long i = 1; i <= 10000000; i++) {
        if (n < i * i) break;
        if (n == i * i) {
            ans = i;
            break;
        }
    }
    
    if (ans != -1) answer=(ans+1) * (ans+1);
    else answer = -1;
    return answer;
}
