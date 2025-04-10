#include <string>
#include <vector>

using namespace std;

// programmers 12921번 소수찾기
// 에라토스테네스의 체

bool visited[1000001] = {false,};

int solution(int n) {
    int answer = 0;
    
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            int n = 1;
            answer++;
            for (int j = i; j < 1000001; j=i*n ) {
                visited[j] = true;
                n++;
            }
        }
    }
    
    return answer;
}
