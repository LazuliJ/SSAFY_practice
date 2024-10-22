// Programmers Level 2. 70129번 이진 변환 반복하기
#include <string>
#include <vector>

using namespace std;

int ans[2] = {0, 0};

// 0 제거
string kill_zero(string s) {
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') tmp+= s[i];
        else ans[1]++;
    }
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    while (s != "1") {
        ans[0]++;
        s = kill_zero(s);
        int slen = s.length();
        s = "";
        // 2진수 변환
        while (slen != 0) {
            s+=to_string(slen%2);
            slen/=2;
        }
    }
    answer.push_back(ans[0]);
    answer.push_back(ans[1]);
    return answer;
}
