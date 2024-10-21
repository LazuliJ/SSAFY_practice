// Level 2. Programmers 최댓값과 최솟값

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    
    string tmp;
    vector<int> vec;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i]== ' ') { // 이 조건을 !=로 잘못 써서 오류가 났는데, 이는 "" 또는 초기화되지 않은 string 형태의 대입으로 인한 오류 인것으로 보임.
            vec.push_back(stoi(tmp));
            tmp="";
        }
        else {
            tmp += s[i];
        }
    }
    vec.push_back(stoi(tmp));
    
    string answer = "";
    sort(vec.begin(), vec.end());
    answer = to_string(vec[0]) + " " + to_string(vec[vec.size()-1]);
    
    return answer;
}
