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

    해당 문제)
    programers -> level3 -> 저울
    이 문제에서 for문 안에 +1 연산을 할 경우 for문이 실행되지 않았을 때 경우를 고려할 수 없게 된다. 항상 모든 케이스가 for문에 들어오는지 생각해서 문제를 풀자
    bool cmp(int a, int b) { return a < b;}
    int solution(vector<int> weight) {
        int answer = 0;
        sort(weight.begin(), weight.end(), cmp);
        answer += weight[0];
        for(int i = 1 ; i < weight.size() ; i++){
            if(weight[i] > answer+1){
                //여기서 뭔가 answer+1을 옮기는 코드를 쓰면 이 for문이 돌지 않는 경우를 고려할 수 없기 때문에 틀리게 된다.
                break;
            }else {
                answer += weight[i];
            }
        }
        return answer+1;
    }

    programers -> level3 -> nqueens 같은 경우
    고려해야 할 경우의 수를 최대한 제한 한 상태로 dfs를 시행한다.

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
    vector<int> v(4, 1); [1,1,1,1] 초기화
    vector<bool> v(4); [flase, false, false, false]

    2차원 벡터
    vector<vector<int> > vec;
    vector<int> tmp;
    tmp.push_back(1~10);
    vec.push_back(tmp);

    2차원 벡터 초기화
    vector<vector<bool>> graph(n,vector<bool>(n,false));

## deque
    #include <deque>
    벡터와 단점을 보완하는 자료구조
    deque<int> dq;
    dq.front();
    dq.pop_front();
    dq.back()
    dq.pop_back();
    앞 뒤로 삽입, 제거가 가능한 자료구조.
    벡터는 원소가 추가될 때 마다 메모리 재할당 후 복사하기에 성능저하의 문제가 있음
    덱은 일정크기의(커다란) 메모리 블록을 할당해 사용하고 부족해지면 더큰 공간 할당 받아서 사용. 위 문제를 개선 (메모리 공간이 비효율적이지 않을까?..)
    vector와 같은 메커니즘으로 sort함수 쓸 수 있음

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
    programers -> level3 -> 디스크 컨트롤러

    min heap은 부모노드가 작은 수
    max heap은 부모노드가 큰 수
    #include <queue>
    priority_queue< int, vector<int>, less<int> > pq; max heap
    priority_queue< int, vector<int>, greater<int> > pq; min heap

    pq.top() // 맨위 값 보기, 다른 자료구조는 front인데 얘는 특이

    heap의 cmp부분 정의하는 방법.
    struct cmp_min {
        bool operator()(vector<int> a, vector<int> b){
            return a[1] > b[1]; // sort의 cmp와 반대느낌이다.
        }
    };

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

    해당 문제)
    programers -> level3 -> 네트워크
    재귀 함수를 통한 BFS

    해당 문제)
    programers -> level3 -> 가장 먼 노드
    queue를 이용한 BFS
    연결 여부 판단하는 2차원 벡터, 방문 여부 판단하는 1차원 벡터, queue가 빌 때 까지 반복하여 2차원 벡터 순회

    programers -> level3 -> 단어변환
    queue 이용
    중복되지 않게 vector<bool> 체크리스트를 썼으며 마킹한 후 큐에 푸쉬하고 다시 그 마킹된 값을 초기화 시켜줘야함. 왜냐하면 마킹된 값이 누적되기 때문

## DFS
    해당 문제)
    programers -> level3 -> 여행경로

    programers -> level3 -> N-nqueens

    쉽게 dfs로 푼다는 점은 유추할 수 있지만 조건을 판단하는 부분을 최대한 줄여나가야 한다.
    퀸의 배치 여부를 매 지점마다 체크해서 문제를 푸는 것 보다 퀸의 배치 여부가 결정되면 둘수 없는 부분을 사전에 표시하여 둘 수 있는 자리만 탐색하는 방법이 더 시간이 적게 걸린다.(처음에 접근한 마킹 방식이 시간상의 이득이 컸다.)
    처음에 2중 for문으로 i = x, j = y로 초기화해 dfs를 진행했는데 이렇게 하면 당연히 x, y 지점 이후로는 y부터 탐색하기 때문에 잘 동작할 리가 없다. 이부분에서 너무 많이 헤맸다. 가로 축은 당연히 0부터 판단해야 다음 퀸이 결정될 모든 후보군을 다 탐색할 수 있게 된다. 이부분 까지 해결하여 테스트 케이스를 맞췄지만 11번째 테스트 케이스에서 자꾸 타임아웃이 걸렸다.
    (마킹 형식이 아니라 매 지점마다 check 했던 풀이의 경우)퀸을 둘 수 없는 자리를 마킹할 때 위에서 아래로 탐색함으로 아래지점은 당연히 비어있기 때문에 현재의 위쪽 세로, 오른쪽 대각선, 왼쪽 대각선 이렇게 세 방향으로만 탐색을 진행해 연산 수를 줄일 수 있다. 이전엔 가로, 세로 대각선 위 아래 모두 탐색했기 때문에 2배 더 비효율 적이었다. 하지만 문제의 가장 큰 핵심은 check가 아니었다.
    문제의 원인은 2중for문으로 생각해보면 퀸의 자리가 결정되면 그 가로줄은 자동으로 쓸 수 없게 된다. 따라서 기존 문제처럼 2중 for문으로 순차적으로 탐색해갈 필요 없이 퀸이 결정되면 바로 다음줄(x+1)로 넘겨 그 줄의 가로를 탐색해 가능한 후보군을 찾아도 문제없이 동작한다. 즉 가로축에 대한 (0 - len)탐색만 진행하면 되는 것이며 for문 하나로 연산을 줄일 수 있고 이게 결정적으로 시간을 감소시켰다.
    테스트 10 기준으로
    맨처음 가장 비효율적으로 짰을 때 (6000ms)
    1중 for문으로 바꿨을 때(check 방식으로 매 턴마다 가능여부 탐색) (32ms)
    1중 for문으로 바꾸고 첫 접근 방식인 퀸이 결정 될 때 마킹하는 방식 (18ms)


## DP
    해당 문제)
    programers -> level2 -> 땅따먹기
    programers -> level3 -> 정수삼각형
    programers -> level3 -> 보행자천국
    programers -> level3 -> 거스름돈
    발상이 너무 어려운 dp문제다.. 이 식을 유추할 수 있어야한다..
    j < money[i] 일때 dp[i][j] = dp[i-1][j]
    아닐 경우엔 dp[i][j] = dp[i-1][j] + dp[i][j-money[i]]
    이런 식이 나오는데 위 경우를 굳이 계산할 필요없이 식을 정리해
    for(j = money[i] ; j <= n ; j++) 이런식으로 최적화가 가능하고 굳이 2차원 말고
    1차원 dp로 문제를 해겷할 수 있다.

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

## 크루스칼
    programers -> level3 -> 섬 연결하기
    최소신장 트리 문제 해결
    정점이 n개인 그래프의 간선중 일부인 n-1개의 간선을 선택해서 모든 정점을 연결한 트리중 가중치의 합이 최소인 트리

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
    -> 너무 어렵게 생각하지 말고 input scale 생각해서 짜기
    programers -> level2 -> [1차]캐시 (카카오)
    -> 여러 자료구조, algorithm 헤더의 transform함수 사용, tolower 함수 캐스팅 조건
    programers -> level2 -> 후보키 (카카오)
    -> 후보키의 후보들중 최소성 위반 제거하는 반복문 조건 까다로움. dfs로 후보를 찾기 때문에 012 02 순 서로 후보가 나올 수 있고 이때 012가 제거되야하는 조건은 0과 2 모두가 검출되어야 하는 부분을 구현해야함.
    programers -> level3 -> N으로 표현
    -> dp문제라고는 하는데 dp로 못풀겠다.. dfs로 풀어보기
    programers -> level3 -> 섬 연결하기
    -> 전형적인 크루스칼 문제
    programers -> level3 -> 여행경로
    -> dfs와 string sorting 혼합 문제. 그동안 푼 문제의 유형 안에 풀림
    programers -> level3 -> 저울
    -> acm icpc 2018 A번 블록체인 문제랑 굉장이 유사한 발상으로 풀수있음. brute force로 다 찾아서 하는게 아님. 이 문제에서 중요한건 for문이 실행 안될 수 도 있는 경우를 생각해서 코드를 짜야한다.
    programers -> level3 -> 보행자 천국
    -> 흔한 그래프의 경로의 수 를 dp로 푸는 문제유형이지만 기존과 다르게 두개의 그래프를 따로 계산해 문제를 해결한다.
    programers -> level3 -> nqueens
    -> dfs푸는 발상까지는 쉽지만 시간 최적화를 위해 최대한 경우의 수를 줄여서 탐색해야한다.
    programers -> level3 -> 거스름돈
    -> 발상이 너무 어려운 dp문제다.. 시간 최적화가 너무 어려움
    programers -> level3 -> 방문길이
    -> 맵으로 접근했는데 1,1 -> 1,2 와 1,2 -> 1,1 이 한 방문에 생기는 선분 쌍으로 맵의 전체 크기의 반 만큼이 정답이 된다. 
