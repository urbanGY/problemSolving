#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int cnt = 0;
    string tmp = "";
    stack<char> st;

    for(int i = 0 ; i < arrangement.size() ; i++){
        if(arrangement[i] == '(' && arrangement[i+1] == ')'){
            i++;
            tmp += '*';
        }else {
            tmp += arrangement[i];
        }
    }
    for(const auto& c : tmp){
        if(c == '*' && st.empty()) continue;
        if(c == ')'){
            int iron_cnt = 0;
            while(true){
                char cur = st.top();
                st.pop();
                if(cur == '*') iron_cnt++;
                else {
                    answer += (iron_cnt + 1);
                    if(!st.empty()){
                        for(int i = 0 ; i < iron_cnt ; i++)
                            st.push('*');
                    }
                    break;
                }
            }
        }else {
            st.push(c);
        }
    }
    return answer;
}
