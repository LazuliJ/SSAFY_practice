// Programmers Level 2. 12953번 N개의 최소공배수

#include <string>
#include <vector>

using namespace std;

/*최대공약수, 최소공배수 구하는 문제*/

/*
쉽게 구하는 법
1. 최대공약수: 2개의 수 중 큰수를 a, 작은 수를 b라고 한다.
2. a를 b로 나눈 나머지 수와 b를 새로운 b, a로 각각 삼는다.
3. 나머지가 0이 될 때까지 반복하고, 나머지가 0이 될 때 b의 값이 최대공약수

1. 최소공배수: 2개의 수를 곱하고, 최대공약수로 그 값을 나누면 최소공배수를 구할 수 있다.
*/

int ln, mn;

int solution(vector<int> arr) {
    int answer = 0;
    
    for (int i = 0; i < arr.size()-1; i++) {
        int a, b;
        a = max(arr[i], arr[i+1]);
        b = min(arr[i], arr[i+1]);
        while (a % b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        ln = b;
        mn = (arr[i] * arr[i+1]) / ln;
        arr[i+1] = mn;
    }
    answer = arr[arr.size()-1];
    return answer;
}
