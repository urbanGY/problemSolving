#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//그래프 위상정렬의 핵심은 각 vertex의 indegree의 숫자를 기록하고 0인 vertex를 push한다
//큐에서 팝된 vertex에게 indegree 값을 영향받는 vertex들의 indegree를 하나씩 줄이며 이 과정에서 indgree가 0이 되면 큐에 push한다.
//vertex간 연결 관계는 배열이 계산이 빠르나 입력크기가 너무 크면 선언 자체가 불가능해짐으로 크기를 고려해 vector나 array를 적절히 활용한다.

int main(){
  int N, M;
  scanf("%d %d",&N, &M);
  vector<int> check[N];//2차원 배열로 선언시 최대 32000*32000이 될 수 있고 이는 메모리 초과를 야기함으로 vector로 관리
  int indegree[N];
  for(int i = 0 ; i < N ; i++){
    indegree[i] = 0;
  }

  for(int i = 0 ; i < M ; i++){
    int a, b;
    scanf("%d %d",&a,&b);
    check[a-1].push_back(b-1);
    indegree[b-1]++;
  }

  queue<int> Q;
  for(int i = 0 ; i < N ; i++){
    if(indegree[i] == 0){
      Q.push(i);
      indegree[i] = -1;
    }
  }
  while(!Q.empty()){
    int now = Q.front();
    Q.pop();
    printf("%d ",now+1);
    for(unsigned int i = 0 ; i < check[now].size() ; i++){//나에게 indegree를 주는 vertex가 pop되면 indegree가 하나씩 감소한다.
      int next = check[now][i];//check[now].at(i)로 할 수도 있으나 속도가 느림
      indegree[next]--;
      if(indegree[next] == 0){
        Q.push(next);
        indegree[next] = -1;
      }
    }
  }
  return 0;
}
