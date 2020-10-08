#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long maxVal = -1;

vector<char> oper;
vector<bool> check;

long long myABS(long long a) {
    return a > 0 ? a : -a;
}
void find(vector<string> expression, vector<char> pick) {
    for(auto c : pick) {
        vector<string> tmp;
        long long before = 0;
        for(int i = 0 ; i < expression.size() ; i++) {
            if(c == '-' && expression[i] == "-") {
                long long cal = before - stoll(expression[i+1]);
                before = cal;
                tmp.pop_back();
                i++;
                tmp.push_back(to_string(cal));
            }else if(c == '+' && expression[i] == "+") {
                long long cal = before + stoll(expression[i+1]);
                before = cal;
                tmp.pop_back();
                i++;
                tmp.push_back(to_string(cal));
            }else if(c == '*' && expression[i] == "*") {
                long long cal = before * stoll(expression[i+1]);
                before = cal;
                tmp.pop_back();
                i++;
                tmp.push_back(to_string(cal));
            }else if(expression[i] != "*" && expression[i] != "+" && expression[i] != "-"){
                before = stoll(expression[i]);
                tmp.push_back(expression[i]);
            }else {
                tmp.push_back(expression[i]);
            }
        }
        expression = tmp;
        // for(auto tmp : tmp) {
        //     cout<<tmp<<" ";
        // }
        // cout<<endl;
    }
    long long result = stoll(expression[0]);
    if(maxVal < myABS(result)) maxVal = myABS(result);
}

void combination(vector<char> pick, vector<string>& expression) {
    if(pick.size() == 3) {
        find(expression,pick);
        return;
    }
    for(int i = 0 ; i < 3 ; i++) {
        if(!check[i]) {
            pick.push_back(oper[i]);
            check[i] = true;
            combination(pick,expression);
            check[i] = false;
            pick.pop_back();
        }
    }
}
long long solution(string expression) {
    long long answer = 0;
    oper.push_back('+');
    oper.push_back('-');
    oper.push_back('*');
    check = vector<bool>(3,false);
    vector<string> express;
    string tmp = "";
    for(auto c : expression) {
        if(c >= '0' && c <= '9') tmp += c;
        else {
            express.push_back(tmp);
            tmp = "";
            tmp += c;
            express.push_back(tmp);
            tmp = "";
        }
    }
    express.push_back(tmp);
    combination(vector<char>(),express);
    answer = maxVal;
    return answer;
}
