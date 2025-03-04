#include <string>
#include <vector>

using namespace std;

// 프로그래머스 389479 서버 증설 횟수 - 수학

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int servers[24] = {0,};
    for (int i = 0; i < 24; i++) {
        int server_needed = (players[i] / m);
        if (servers[i] < server_needed) {
            int new_server = server_needed - servers[i];
            answer += new_server;
            for (int j = 0; j < k; j++) {
                if(i+j >= 24) break;
                servers[i+j] += new_server;
            }
        }
    }
    
    return answer;
}
