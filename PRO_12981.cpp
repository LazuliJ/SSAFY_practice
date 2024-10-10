#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    
    for (int i = 1; i < words.size(); i++) {
        string str = words[i];
        if (answer[0]!= 0 and answer[1]!=0) break;
        for (int j = 0; j<i; j++) {
            if (str == words[j] or str[0] != words[i-1][words[i-1].length()-1] or str.length() == 1) {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                break; // break문을 써주어야 가장 먼저 탈락한 사람을 알 수 있다.
            }
        }
    }
    
    
    if (words[0].length() == 1) { answer[0] = 1; answer[1] = 1; }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "Hello Cpp" << endl;

    return answer;
}
