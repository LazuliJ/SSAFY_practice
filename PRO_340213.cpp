#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    // commends를 읽어온다.
    int video_len_int = (60 * ((int(video_len[0])-int('0')) * 10 +  (int(video_len[1])-int('0')))) + ((int(video_len[3])-int('0')) * 10 +  (int(video_len[4])-int('0')));
    
    int pos_int = (60 * ((int(pos[0])-int('0')) * 10 +  (int(pos[1])-int('0')))) + ((int(pos[3])-int('0')) * 10 +  (int(pos[4])-int('0')));
    
    int op_start_int = (60 * ((int(op_start[0])-int('0')) * 10 +  (int(op_start[1])-int('0')))) + ((int(op_start[3])-int('0')) * 10 +  (int(op_start[4])-int('0')));
    
    int op_end_int = (60 * ((int(op_end[0])-int('0')) * 10 +  (int(op_end[1])-int('0')))) + ((int(op_end[3])-int('0')) * 10 +  (int(op_end[4])-int('0')));
    
    for (int i = 0; i < commands.size(); i++) {
        if (pos_int >= video_len_int) pos_int = video_len_int;
        if (pos_int <= 0) pos_int = 0;
        if (pos_int >= op_start_int and pos_int <= op_end_int) pos_int = op_end_int;
        
        if (commands[i] == "next") {
            pos_int += 10;
        }
        else if (commands[i] == "prev") {
            pos_int -= 10;
        }
    }
    if (pos_int >= video_len_int) pos_int = video_len_int;
    if (pos_int <= 0) pos_int = 0;
    if (pos_int >= op_start_int and pos_int <= op_end_int) pos_int = op_end_int;
    
    if ((pos_int / 60) < 10) {
        answer += "0";
        answer += to_string((pos_int/60));
    }
    else {
        answer += to_string((pos_int/60));
    }
    
    answer += ":";
    
    if ((pos_int % 60) < 10) {
        answer += "0";
        answer += to_string((pos_int%60));
    }
    else {
        answer += to_string((pos_int%60));
    }
    
    return answer;
}
