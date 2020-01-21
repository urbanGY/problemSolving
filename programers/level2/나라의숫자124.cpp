#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string solution(int n) {
    string answer = "";
    stack<char> st;
    while(n){
        int mod = n%3;
        if(mod == 1){
            st.push('1');
        }else if(mod == 2){
            st.push('2');
        }else{
            st.push('4');
            n -= 3;
        }

        n /= 3;
    }
    while(!st.empty()){
        char cur = st.top();
        st.pop();
        answer += cur;
    }
    return answer;
}
