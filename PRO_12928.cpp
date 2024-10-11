// Level 1. 12928번 약수의 합
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    // 당연하지만, 0은 포함되면 안된다. (할시 floating point~~ 에러 발생)
    for (int i = 1; i <= n; i++) {
        if (n%i==0) {
            answer += i;
        }
    }
    return answer;
}
