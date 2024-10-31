// 프로그래머스 Level 2. 76502번 괄호 회전하기
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int x = 0; x < s.length(); x++) {
        queue<char> q; // 초기화 조심
        for (int y = 0; y < s.length(); y++) {
            int i = (x+y)%s.length();
            if (x== 2) cout << s[i] << " ";
            q.push(s[i]);
        }
        vector<char> dq;
        int flag = 0;
        for (int y = 0; y < s.length(); y++) {
            char c = q.front(); q.pop();
            if (x==2) cout << c << " ";
            // 현재 c가 열리는 괄호일 때
            if (c == '[' or c == '(' or c == '{') {
                dq.push_back(c);
            }
            // 닫는 괄호일 때
            else {
                if (!dq.empty()){
                    char dc = dq.back(); dq.pop_back();
                    //if (x==2) cout << dc << " " << c << " ";
                    if (dc == '{' and c == '}' or dc == '[' and c == ']' or dc == '(' and c == ')') {
                        continue;
                    }
                    // 모양이 다름
                    else {
                        flag = 1;
                        break;
                    }
                }
                // 비었는데 닫는 괄호를 호출한 경우
                else {
                    flag = 1;
                    break;
                }
            }
        }
        if (!dq.empty() or flag == 1) answer--;
    }
    
    return answer;
}
