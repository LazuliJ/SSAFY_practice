// Programmers Level 1. 42748번 K번째수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0]; int end = commands[i][1]; int ans = commands[i][2];
        vector<int> tmp;
        for (int j = start-1; j < end; j++) {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[ans-1]);
    }
    return answer;
}
