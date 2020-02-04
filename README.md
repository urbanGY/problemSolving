# problemSolving
## tip
    자료형 변환을 할 경우 ex)programers -> level2 -> 멀쩡한사각형
    반환결과를 저장하는 곳 뿐만 아니라 우항의 변수들에도 개별적으로 캐스팅을 반드시 해주자
    피보나치 수 처럼 큰 수 %하라는 계산에는
    tmp = (a%1234567) + (b%12345667);
    c = (tmp%1234567)
    이렇게 세 항목 모두 %해주기

    최대공약수 유클리드 호제법

    int gcd(int a, int b){
    int tmp;
    while(b != 0){
            tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }

    소수구하기
    루트N까지만 나눠보기
    i <= sqrt(n)

    순서마다 실행하기 ex) programers -> level2 -> [3차]n진수게임
    m명이서 뭔가 하는데 내가 p번째 일 때 %써도 좋지만 직관적으로 그냥 m번째 턴이 넘어가면 1번째로 돌리는 코드로 하자.
    int p = 1, m = 2; //내 차례가 p , m명이서 진행
    int turn = 1;
    while(true){
      if(turn == p) something...
      turn++;
      if(turn > m) turn = 1;
    }

    num이 들어왔을 때 n진수로 만들기
    num이 0일때 따로 분리
    10이 넘어가는 잔수의 경우에 A로 바꿔주는 경우는 아래같이
    문제는 결과가 뒤집어져서 저장되기 때문에 거꾸로 세던가 뒤집어주는 과정을 거쳐야한다.
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

    반복문의 탈출 조건은 매회 체크
    매번 가변적인 조건에서 반복문을 돌릴 경우 n < q.size() 로 하고
    아래 코드와 같은 경우에는 상수로 미리 값을 받아서 탈출조건을 만든다.
    int n = 0, end = q.size();
    while(n < end){                
      tmp = q.front();
      q.pop();
      if(tmp != refine_city) q.push(tmp);
      n++;
    }

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

    절대값
    #include <cstdlib> abs() //int 타입 절대값
    #include <cmath> fabs() //float 타입 절대값
    int a = abs(10-9);

    루트
    #include <cmath>
    sqrt(n);

## vector
    #include <vector>
    c11 vector for문
    for(const auto& elem : v){
        cout<<elem<<endl;
    }

    v.back() 맨뒤 값 보기
    v.pop_back() 맨뒤 팝, 즉 스택처럼 쓰기 가능

    vector<int> v(4); [0,0,0,0] 초기화
    vector<bool> v(4); [flase, false, false, false]

    2차원 벡터
    vector<vector<int> > vec;
    vector<int> tmp;
    tmp.push_back(1~10);
    vec.push_back(tmp);


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
    s.substr(2,1) ->"c" // 2번째부터 1개의 문자열을 가져오겠다 라는 뜻

    string 분리하기
    #include <string>
    #include <sstream>
    string s = "a b c d"
    string buf;
    stringstream ss(s);
    while(ss >> buf)
      cout<<buf<<endl;

    string 분리 공백 외의 경우
    while(getline(ss,buf,',')){ //이렇게하면 , 로 나눠줌.
      cout<<buf<<endl;
    }

    string 모두 소문자 or 대문자로 만들기, tolower/toupper 앞에 캐스팅을 해줘야 컴파일을 함
    #include <algorithm>
    #include <string>
    string refine_city = cities[i];
    **transform(refine_city.begin(), refine_city.end(), refine_city.begin(), (int(*)(int))tolower**

    string s = "";
    char a = 'a', b = 'b';
    s = a+b;
    이렇게 하면 a+b를더한 아스키코드값이 s에 대입된다.
    s = "ab" 이렇게 되는게 아니다!




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
    programers -> level2 -> 영어끝말잇기

    #include <map>
    map<key, value> m;
    m[key] = value;

    검색할때
    if(m.find(key) == m.end()) key가 map에 없음

    insert문
    pair<map<int, int>::iterator, bool > pr;

    pr = m.insert(pair<int, int>(10, 30));
    if (true == pr.second)
        cout << "key : " << pr.first->first << ", value : " << pr.first->second << " 저장 완료!" << endl;
    else
        cout << "key 10가 이미 m에 있습니다." << endl;

    map iterator 선언방법 및 사용법
    map<string, bool>::iterator i;
    for(i = m.begin() ; i != m.end() ; i++)
        cout<<i->first<<endl;


## BFS
    해당 문제)
    programers -> level2 -> 카카오프렌 컬러링북

## DP
    해당 문제)
    programers -> level2 -> 땅따먹기

## 순열만들기
    해당 문제)
    programers -> level2 -> 단체사진찍기(kakao)

    전역변수로 할 경우
    vector<bool> check(8);
    vector<char> pick(8);
    string candidate = "ACFJMNRT";

    void find(int index){
      if(index == 8) return;

      for(int i = 0 ; i < 8 ; i++){
        if(!check[i]){
          check[i] = true;
          pick[i] = candidate[i];
          find(index+1);
          check[i] = false;
        }
      }
    }

## 조합만들기
    해당 문제)
    programers -> level2 -> 소수만들기

    void find(vector<int>& nums, int n, int start, int target){ //n이 반복횟수, start가 시작점, target이 목표 값
        if(n == 0){
            if(is_prime(target)) cnt++;
            return;
        }

        for(int i = start ; i < len ; i++){
            find(nums, n-1, i+1, target + nums[i]);
        }
    }

## 다시 볼 문제
    programers -> level2 -> 멀쩡한사각형
    -> 대각선이 지나가지 않는 사각형 유도 방법
    programers -> level2 -> 다리를 지나는 트럭
    -> 처음엔 안풀렸는데 다시 차분하게 풀어보니 풀림
    programers -> level2 -> 라면공장
    -> 시뮬레이션 문제 잘 읽고 하기
    programers -> level2 -> 가장 큰 정사각형
    -> brute force로 안되면 dp로 생각해보기
    programers -> level2 -> 조이스틱
    -> 단순 순회가 아니라 매 지점마다 최소거리 탐색 후 이동, 바꿔야할 수 cnt로 계산
    programers -> level2 -> 가장큰수
    -> 스트링 간 비교, nhn문제랑 유사
    programers -> level2 -> 소수찾기
    -> 순열 만들기 할게 아니라 스트링 정렬 후 나올 수 있는 숫자 내에서 소수 여부 판단하는 접근방식
    programers -> level2 -> N개의 최소공배수
    -> gcd, lcm의 깔금한 계산 코드, 여러개의 최대공배수를 갖기위한 재귀적 접근방식
    programers -> level2 -> 영어끝말잇기
    -> map insert로 중복 단어 체크방법
    programers -> level2 -> [1차]뉴스클러스터 (카카오)
    너무 어렵게 생각하지 말고 input scale 생각해서 짜기
    programers -> level2 -> [1차]캐시 (카카오)
    여러 자료구조, algorithm 헤더의 transform함수 사용, tolower 함수 캐스팅 조건
    programers -> level2 -> 후보키 (카카오)
    후보키의 후보들중 최소성 위반 제거하는 반복문 조건 까다로움. dfs로 후보를 찾기 때문에 012 02 순서로 후보가 나올 수 있고 이때 012가 제거되야하는 조건은 0과 2 모두가 검출되어야 하는 부분을 구현해야함.
    programers -> level3 -> N으로 표현
    dp문제라고는 하는데 dp로 못풀겠다.. dfs로 풀어보기
