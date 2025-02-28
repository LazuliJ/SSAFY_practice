#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt[11] = {0,};
int cor_cnt = 0;
vector<vector<int>> qnum;
int ans_num[11];

void DFS(int depth, int max_num, int last_num) {
    if (depth == 5) {
        int if_cor = 1;
        for (int i = 0; i < qnum.size(); i++) {
            if (ans_num[i] != cnt[i]) {
                if_cor = 0;
                break;
            }
        }
        if (if_cor == 1) cor_cnt++;
        return;
    }
    for (int i = last_num+1; i <= max_num; i++) {
        int tmp_cnt[11] = {0,};
        for (int j = 0; j < qnum.size(); j++) {
            for (int k = 0; k < 5; k++) {
                if (qnum[j][k] == i) {
                    tmp_cnt[j] = 1;
                    break;
                }
            }
            cnt[j] += tmp_cnt[j];
        }
        int if_cor = 1;
        for (int j = 0; j < qnum.size(); j++) {
            if (ans_num[j] < cnt[j]) {
                if_cor = 0;
                break;
            }
        }
        if (if_cor == 1) DFS(depth+1, max_num, i);
        for (int j = 0; j < qnum.size(); j++) {
            cnt[j] -= tmp_cnt[j];
        }
        
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    for (int i = 0; i < q.size(); i++) {
        qnum.push_back(q[i]);
        ans_num[i] = ans[i];
    }
    DFS(0, n, 0);
    answer = cor_cnt;
    return answer;
}
