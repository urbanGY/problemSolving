#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> st;
    int length = heights.size();

    for(int i = heights.size()-1 ; i >= 0 ; i--){
        for(int j = i-1 ; j >= 0 ; j--){
            if(heights[j] > heights[i]){
                st.push(j+1);
                break;
            }

            if(j == 0)
                st.push(0);
        }
    }
    st.push(0);
    while(!st.empty()){
        int a = st.top();
        answer.push_back(a);
        st.pop();
    }
    return answer;
}
