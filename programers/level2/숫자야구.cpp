#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(vector<vector<int> >& baseball, int input[]) {
    for(const auto& elem : baseball){
        int num = elem[0], strike = elem[1], ball = elem[2];
        int strike_cnt = 0, ball_cnt = 0, candidate[3] = {num/100, (num%100)/10, num%10};

        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(i == j && candidate[i] == input[j]) strike_cnt++;
                else if(candidate[i] == input[j]) ball_cnt++;
            }
        }
        if(strike_cnt == strike && ball_cnt == ball) continue;
        else return false;
    }
    return true;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int a = 1 ; a <= 9 ; a++){
        for(int b = 1 ; b <= 9 ; b++){
            for(int c = 1 ; c <= 9 ; c++){
                if((a == b) || (b == c) || (a == c)) continue;
                int input[3] = {a,b,c};

                if(check(baseball, input)) answer++;
            }
        }
    }
    return answer;
}
