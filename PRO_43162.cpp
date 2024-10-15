// 프로그래머스 Level 3. 43162번 네트워크 - DFS
#include <string>
#include <vector>

/*
전략이랄게 딱히 없고, DFS로 완탐 돌리면서 
서로 이어진 노드를 visited처리해주면서 센다.
*/

using namespace std;

int visited[201] = {0,};
int net = 0;
vector<vector<int>> com;

void DFS(int i, int num) {
    visited[i] = num;
    for(int j = 0; j < com[i].size(); j++) {
        if(com[i][j] == 1 and j != i and visited[j]==0) DFS(j, num);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    com = computers;
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            net++;
            DFS(i, net);
        }
    }
    
    answer = net;
    return answer;
}
