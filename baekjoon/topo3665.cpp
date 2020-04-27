#include <iostream>
#include <queue>
using namespace std;

int main(){
  int N, n, c;
  scanf("%d",&N);
  for(int t = 0 ; t < N ; t++){
    scanf("%d",&n);
    n++;
    int indegree[n];
    int answer[n];
    int input[n];
    bool check[n][n];
    for(int i = 1 ; i < n ; i++){
      scanf("%d",&input[i]);
      indegree[input[i]] = i-1;
      for(int j = 1 ; j < n ; j++)
        check[i][j] = false;
    }
    for(int i = 2 ; i < n ; i++){
      for(int j = i-1 ; j >= 1 ; j--){
        check[input[i]][input[j]] = true;
      }
    }
    scanf("%d",&c);
    for(int i = 0 ; i < c ; i++){
      int a, b;
      scanf("%d %d",&a,&b);
      if(check[a][b]){
        check[a][b] = false;
        check[b][a] = true;
        indegree[a] -= 1;
        indegree[b] += 1;
      }else {
        check[a][b] = true;
        check[b][a] = false;
        indegree[a] += 1;
        indegree[b] -= 1;
      }
    }
    queue<int> Q;
    for(int i = 1 ; i < n ; i++)
      if(indegree[i] == 0)
        Q.push(i);
    for(int i = 1 ; i < n ; i++){
      if(Q.size() > 1){
        printf("?\n");
        goto WRONG;
      }
      if(Q.empty()){
        printf("IMPOSSIBLE\n");
        goto WRONG;
      }
      int now = Q.front();
      indegree[now] = -1;
      Q.pop();
      answer[i] = now;
      for(int j = 1 ; j < n ; j++){
        if(indegree[j] > 0) indegree[j] -= 1;
        if(indegree[j] == 0) Q.push(j);
      }
    }
    for(int i = 1 ; i < n ; i++)
      printf("%d ",answer[i]);
    printf("\n");
    WRONG:;
  }
  return 0;
}
