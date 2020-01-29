#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> st;
    for(auto c : s){
        if(st.empty()){
            st.push_back(c);
        }else {
            char tmp = st.back();
            if(c == tmp)
                st.pop_back();
            else
                st.push_back(c);
        }
    }
    if(st.empty()){
        answer = 1;
    }else {
        answer = 0;
    }
    return answer;
}
