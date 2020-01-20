# problemSolving
## tip
    자료형 변환을 할 경우 ex)programers -> level2 -> 멀쩡한사각형
    반환결과를 저장하는 곳 뿐만 아니라 우항의 변수들에도 개별적으로 캐스팅을 반드시 해주자
    
## dp1010 다리놓기
    n C r = n-1 C r-1 + n-1 C r
	factorial 은 unsigned long long int 해도 20 몇? 부터는 계산이 안됨

## math
    헤더 <cmath>
    올림 ceil(4.2) -> 5.0 (float)(double)(long double)
    ex) int val = (int)(ceil((float)n/speeds[i]));

    #include <string>
    #include <vector>
    #include <cmath>
    #include <iostream>
    using namespace std;

    vector<int> solution(vector<int> progresses, vector<int> speeds) {
        int length = progresses.size();
        vector<int> tmp;
        for(int i = 0 ; i < length ; i++){
            int n = 100 - progresses[i];
            int val = (int)(ceil((float)n/speeds[i]));
            tmp.push_back(tmp);
        }
        vector<int> answer;
        return answer;
    }

## vector
    #include <vector>
    c11 vector for문
    for(const auto& elem : v){
        cout<<elem<<endl;
    }

## stack
    #include <stack>
    stack<int> st;
    st.push(0);
    a = st.top();
    st.pop();
    st.empty();
