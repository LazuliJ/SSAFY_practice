// Programmers Level 2. 138476번 귤 고르기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// struct 연산자 오버로딩
/* 구조체 내부에 bool operator<(const [구조체] [이름]) const 선언 */

struct tang{
    int num; // 귤 크기
    int cnt; // 귤 개수
    bool operator<(const tang t) const {
        if (cnt > t.cnt) return true;
        if (cnt < t.cnt) return false;
        return false;
    }
};

int DAT[10000001] = {0,}; // 해당 크기의 귤이 count되었는지 확인하기 위해 DAT이용

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<tang> tang_vec; // 귤 구조체 벡터
    for (int i = 0; i < tangerine.size(); i++){
        if (DAT[tangerine[i]] == 1) {
            for (int j = 0; j < tang_vec.size(); j++) {
                if (tang_vec[j].num == tangerine[i]) {
                    tang_vec[j].cnt++;
                    break;
                }
            }
        }
        else {
            DAT[tangerine[i]] = 1;
            tang t;
            t.num = tangerine[i];
            t.cnt = 1;
            tang_vec.push_back(t);
        }
    }
    
    sort(tang_vec.begin(), tang_vec.end());
    int total_cnt = 0;
    for (int i = 0; i < tang_vec.size(); i++) {
        total_cnt += tang_vec[i].cnt;
        answer++;
        if (total_cnt >= k) {
            break;
        }
    }
    
    return answer;
}
