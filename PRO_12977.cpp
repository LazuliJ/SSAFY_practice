#include <vector>
#include <iostream>
using namespace std;

int visited[50001] = {0,};

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> nums_sum;
    
    // 에라토스테네스
    for (int i = 2; i < 50001; i++) {
        if (visited[i] == 1) continue;
        else {
            int tmp = 2;
            while (tmp * i < 50001) {
                visited[tmp*i] = 1;
                tmp++;
            }
        }
    }
    
    for (int i = 0; i < nums.size()-2; i++) {
        for (int j = i+1; j < nums.size()-1; j++) {
            for (int t = j+1; t < nums.size(); t++) {
                nums_sum.push_back(nums[i] + nums[j] + nums[t]);
            }
        }
    }
    
    for (int i = 0; i < nums_sum.size(); i++) {
        int numnum = nums_sum[i];
        cout << visited[numnum] << " ";
        if (visited[numnum] == 0) answer++;
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}
