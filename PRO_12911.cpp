// Programmers Level 2. 12911번 다음 큰 숫자

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string change(int n) {
    string str = "";
    // 코드 반복문 밖으로 나와있어서 무한 루프 돌고 있었음;;
    while (n!=0) {
        str+= to_string(n%2);
        n /= 2;
    }
    return str;
}

int count_one(string str){
    int one = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') one++;
    }
    return one;
}

int solution(int n) {
    int answer = n;
    string ans_num = "";
    string n_num = change(n);
    int n_one = count_one(n_num);
    while (count_one(ans_num) != n_one) {
        answer++;
        ans_num = change(answer);
    }
    return answer;
}
