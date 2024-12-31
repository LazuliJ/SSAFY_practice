#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 백준 3961번 터치스크린 키보드

int t;
int DAT[26][2] = {0,}; 

// 문자열과 정답 문자열에서부터의 길이 저장
struct word {
    string sp = "";
    int dist = 0;
    bool operator< (word next) const{
        if (dist < next.dist) return true;
        if (dist > next.dist) return false;

        if (sp < next.sp) return true;
        if (sp > next.sp) return false;
        return false;
    };
};

// 정답 문자열으로부터의 길이를 구하는 함수
int cal_dist(word ans, word tar) {
    int leng = 0;;
    for (int i = 0; i < ans.sp.length(); i++) {
        int ans_y = DAT[int(ans.sp[i])-int('a')][0];
        int ans_x = DAT[int(ans.sp[i])-int('a')][1];

        int tar_y = DAT[int(tar.sp[i])-int('a')][0];
        int tar_x = DAT[int(tar.sp[i])-int('a')][1];
        leng += abs(ans_y-tar_y)+abs(ans_x-tar_x);
    }
    return leng;
}

// 초기화(문자열배열의 위치를 DAT에 저장)
void init() {
    string str[3] {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < str[i].size(); j++) {
            int alpha = int(str[i][j])-int('a');
            DAT[alpha][0] = i;
            DAT[alpha][1] = j;
        }
    }
}

// main
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        word ans;
        int num;
        vector<word> dict;

        cin >> ans.sp >> num;
        for (int i = 0; i < num; i++) {
            word w;
            cin >> w.sp;
            w.dist = cal_dist(ans, w);
            dict.push_back(w);
        }

        sort(dict.begin(), dict.end());
        for (int i = 0; i < dict.size(); i++) {
            cout << dict[i].sp << " " << dict[i].dist << "\n";
        }
    }
}
