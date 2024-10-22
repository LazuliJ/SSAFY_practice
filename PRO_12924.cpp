// Programmers Level 2. 12924번 숫자의 표현
#include <iostream>
#include <string>
#include <vector>

/*투 포인터 문제
0을 포함하지 않게 조심하자.*/

using namespace std;

int st_po = 1, ed_po = 1;

int solution(int n) {
    int answer = 0;
    while (true) {
        int tmp = 0;
        if (ed_po == n+2) break;
        for (int i = st_po; i < ed_po; i++) {
            tmp+=i;
        }
        if (tmp == n) {
            answer++;
            cout << st_po << " " << ed_po << '\n';
            st_po++;
        }
        else if (tmp > n) {
            st_po++;
        }
        else if (tmp < n) {
            ed_po++;
        }
    }
    return answer;
}
