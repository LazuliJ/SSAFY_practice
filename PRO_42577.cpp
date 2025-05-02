#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 프로그래머스 [전화번호 목록]

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = i+1; j < phone_book.size(); j++) {
            if (phone_book[i][0] != phone_book[j][0]) break;
            if (phone_book[i].size() >= phone_book[j].size()) break;
            for (int l = phone_book[i].length()-1; l>=0; l--) {
                if (phone_book[i][l] != phone_book[j][l]) break;
                if (l == 0) answer = false;
            }
            if (!answer) break;
        }
        if (!answer) break;
    }
    
    return answer;
}
