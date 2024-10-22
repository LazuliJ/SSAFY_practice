// Programmers Level 2. 12945번 피보나치 수
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int nums[2] = {0, 1};
    for (int i = 2; i <= n; i++) {
        int tmp = (nums[0]+nums[1])%1234567;
        nums[0] = nums[1];
        nums[1] = tmp;
    }
    answer = nums[1];
    return answer;
}
