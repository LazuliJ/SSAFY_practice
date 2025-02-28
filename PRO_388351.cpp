#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    vector<int> gift;
    
    for (int i = 0; i < n; i++) {
        gift.push_back(0);
    }
    
    for (int i = 0; i < 7; i++) {
        int now = (startday - 1 + i)%7;
        if (now == 5 or now == 6) continue;
        for (int j = 0; j < n; j++) {
            int goal = schedules[j] + 10;
            if (goal % 100 >= 60) goal = goal + 100 - 60;
            if (timelogs[j][i] <= goal) continue;
            else gift[j] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (gift[i] == 0) answer++;
    }
    
    return answer;
}
