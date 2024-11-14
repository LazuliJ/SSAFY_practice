#include <string>
#include <vector>

using namespace std;

/*
programmers 133502번
stack을 이용해서 ingredient에서 마지막 4개씩 비교해서
햄버거의 순서와 일치하면 제거한다.
*/

int burger[5] = {0, 1, 2, 3, 1};

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> p_stack;
    for (int i = 0; i < ingredient.size(); i++) {
        p_stack.push_back(ingredient[i]);
        int flag = 0;
        if (p_stack.size() >= 4) {
            for (int j = 1; j <= 4; j++) {
                if (p_stack[p_stack.size()-5+j] != burger[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                for (int j = 0; j < 4; j++) {
                    p_stack.pop_back();
                }
                answer++;
            }
        }
    }
    
    return answer;
}
