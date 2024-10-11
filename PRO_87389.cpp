#include <string>
#include <vector>

using namespace std;

// 숫자를 보면 알 수 있는데 그냥 단순루프문으로 해결 가능
int solution(int n) {
    int answer = 0;
    for (int x = 2; x <= 1000000; x++) {
        if (n%x == 1) {
            answer = x;
            break;
        }
    }
    return answer;
}
