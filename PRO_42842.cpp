// Programmers Level 2. 42842번 카펫
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int y = 2; int x = (brown/2 + 2) - y;
    while(true){
        if ((y-2)*(x-2) == yellow) {
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
        y++;
        x = (brown/2 + 2) - y;
    }
    
    return answer;
}
