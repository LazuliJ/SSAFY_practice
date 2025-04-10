#include<vector>
#include<deque>
#include<iostream>
using namespace std;

// 프로그래머스 1844번 게임 맵 최단거리

int Y, X;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int visited[101][101] = {0,};
int MAP[101][101] = {0,};
int ans = 0;
deque<int> dq;

void BFS() {
    dq.push_back(0);
    dq.push_back(0);
    dq.push_back(1);
    visited[0][0] = 1;
    while(!dq.empty()) {
        int y = dq.front(); dq.pop_front();
        int x = dq.front(); dq.pop_front();
        int cur = dq.front(); dq.pop_front();
        if (y == Y-1 and x == X-1) {
            ans = cur;
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            int next = cur + 1;
            
            if (ny < 0 or nx < 0 or ny >= Y or nx >= X) continue;
            if (visited[ny][nx] == 1) continue;
            if (MAP[ny][nx] == 0) continue;
            
            visited[ny][nx] = 1;
            dq.push_back(ny);
            dq.push_back(nx);
            dq.push_back(next);
        }
    }
    
}

void debug() {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    Y = maps.size();
    X = maps[0].size();
    
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            MAP[i][j] = maps[i][j];
        }
    }
    
    BFS();
    //debug(); <- 프로그래머스 환경에서 코드가 맞는데 시간초과나면 입출력 값 있는지 확인
    answer = ans;
    if (visited[Y-1][X-1] != 1) answer = -1;
    
    return answer;
}
