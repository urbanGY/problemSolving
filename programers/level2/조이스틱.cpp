#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int recent = 0;
    int i = 0;
    int length = name.size();
    int cnt = 0;
    map<char, int> m;
    int tmp = 13;

    for(char c = 'N' ; c <= 'Z' ; c++, tmp--)
        m[c] = tmp;

    for(char c = 'A' ; c <= 'M' ; c++, tmp++)
        m[c] = tmp;

    for(const auto& c : name){
        if(c == 'A') cnt++;
    }

    cnt = length - cnt;

    while(true){

        if(name[i] != 'A') cnt--;
        answer += (m[name[i]]);
        name[i] = 'A';
        if(cnt == 0) break;

        int right, left;
        int right_pos, left_pos;
        int pos = i+1, d_cnt = 1;
        if(pos == length) pos = 0;
        while(name[pos] == 'A'){
            d_cnt++;
            pos++;
            if(pos == length) pos = 0;
        }
        right = d_cnt;
        right_pos = pos;

        pos = i-1;
        d_cnt = 1;
        if(pos == -1) pos = length-1;
        while(name[pos] == 'A'){
            d_cnt++;
            pos--;
            if(pos == -1) pos = length-1;
        }
        left = d_cnt;
        left_pos = pos;

        if(left < right){
            answer += left;
            i = left_pos;
        }else {
            answer += right;
            i = right_pos;
        }

    }
    return answer;
}
// 13  12  11  10  9  8  7  6  5  4  3  2  1    1 2 3 4 5 6 7 8 9 10 11 12
// n o p q r s t u v w x y z a b c d e f g h i j k l m
