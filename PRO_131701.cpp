#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 프로그래머스 131701번 - 브루트포스

int DAT[1000001] = {0,};

int solution(vector<int> elements) {
    
    int answer = 0;
    int el_size = elements.size();
    int initial_idx = 0;
    
    for (int e = 0; e < el_size; e++) {
        int start_idx = initial_idx;
        int end_idx = initial_idx + e;
        while(true) {
            int sum = 0;
            for (int i = start_idx; i <= end_idx; i++) {
                int i_now = i%el_size;
                sum += elements[i_now];
            }
            if(DAT[sum] == 0) answer++;
            DAT[sum] = 1;
            start_idx++;
            end_idx++;
            if (start_idx % el_size == 0) break;
        }
    }
    
    return answer;
}
