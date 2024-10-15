// 프로그래머스 Level 3. 43105 정수 삼각형(동적 계획법 - 기록하면서 풀이하기)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
동적계획법에서 유명한 문제
작은 삼각형으로 나눈후, 밑에서 부터 위로(Bottom-Up) 최댓값을 위의 값에 더해서
최종적으로 가장 위의 값은 최댓값이 된다.
아래로 가면서 모든 경로를 다 탐색하는 것은 시간 초과나므로 주의.
*/

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int level = triangle.size()-2;
    while (level != -1) {
        for (int n = 0; n < triangle[level].size(); n++) {
            triangle[level][n] = triangle[level][n] + max(triangle[level+1][n], triangle[level+1][n+1]);
        }
        level--;
    }
    
    answer = triangle[0][0]; 
    return answer;
}
