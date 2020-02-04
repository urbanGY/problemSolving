#include <string>
#include <vector>
#include <iostream>
using namespace std;
string make_n(int n, int num){
    string result = "";
    if(num == 0) return "0";
    while(num){
        int mod = num%n;
        if(mod >= 10){
            mod -= 10;
            result += ('A' + mod);
        }else {
            result += to_string(mod);
        }
        num /= n;
    }
    return result;
}

string solution(int n, int t, int m, int p) {
    //t*m번
    int num = 0, turn = 1;
    string answer = "";
    while(true){
        string tmp = make_n(n, num);
        for(int i = tmp.size()-1 ; i >= 0 ; i--){
            char c = tmp[i];
            if(turn == p){
                t--;
                answer += c;
                if(t == 0) return answer;
            }
            turn++;
            if(turn > m) turn = 1;
        }
        num++;
    }
    return answer;
}
