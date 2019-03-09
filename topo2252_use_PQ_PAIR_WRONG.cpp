#include <iostream>
#include <utility>
#include <queue>
using namespace std;
struct cmp{
  bool operator()(pair<int, int> a, pair<int, int> b){
    return a.second > b.second; //작은놈부터
  }
};

int main(){
  int N, M;
  scanf("%d %d",&N, &M);
  int indegree[N];
  bool check[N][N];
  for(int i = 0 ; i < N ; i++){
    indegree[i] = 0;
    for(int j = 0 ; j < N ; j++)
      check[i][j] = false;
  }

  for(int i = 0 ; i < M ; i++){
    int a, b;
    scanf("%d %d",&a,&b);
    check[b-1][a-1] = true;
  }
  pair<int, int> now;
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> heap;
  for(int i = 0 ; i < N ; i++){
    heap.push(make_pair(i+1,indegree[i]));
  }

  while(!heap.empty()){
    now = heap.top();
    heap.pop();
    printf("%d ",now.first);
  }

  return 0;
}
