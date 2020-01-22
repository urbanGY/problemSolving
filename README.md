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

## string
    #include <string>
    string = to_string(int);
    int = stoi(string);
    bool cmp(string a, string b)
    return a+b > b+a;
    가장큰수 문제에서의 스크링 정렬 방법

    string s = "abcdef";
    s.substr() -> "abcdef"
    s.substr(2) -> "cdef"
    s.substr(2,1) ->"c"

## stack
    #include <stack>
    stack<int> st;
    st.push(0);
    a = st.top();
    st.pop();
    st.empty();

## heap
    해당 문제)
    programers -> level2 -> 더 맵게

    min heap은 부모노드가 작은 수
    max heap은 부모노드가 큰 수
    #include <queue>
    priority_queue< int, vector<int>, less<int> > pq; max heap
    priority_queue< int, vector<int>, greater<int> > pq; min heap

## map
    해당 문제)
    programers -> level2 -> 전화번호목록

    #include <map>
    map<key, value> m;
    m[key] = value;

    검색할때
    if(m.find(key) == m.end()) key가 map에 없음

## BFS
    해당 문제)
    programers -> level2 -> 카카오프렌 컬러링북

## 다시 볼 문제
    programers -> level2 -> 멀쩡한사각형
    -> 대각선이 지나가지 않는 사각형 유도 방법
    programers -> level2 -> 다리를 지나는 트럭
    programers -> level2 -> 조이스틱
    -> 단순 순회가 아니라 매 지점마다 최소거리 탐색 후 이동, 바꿔야할 수 cnt로 계산
    programers -> level2 -> 가장큰수
    -> 스트링 간 비교, nhn문제랑 유사
    programers -> level2 -> 소수찾기
    -> 순열 만들기 할게 아니라 스트링 정렬 후 나올 수 있는 숫자 내에서 소수 여부 판단하는 접근방식
