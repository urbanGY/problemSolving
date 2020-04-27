#include <iostream>
#include <stdlib.h>
using namespace std;
int max (int, int);

int main(){
  int N = 0;
  scanf("%d",&N);
  int * dp = (int *)calloc(N+1,sizeof(int));

  for(int i = 0 ; i < N ; i++){
    int before = dp[0];
    if(i > 0)
      dp[i] = dp[i-1]; //if문 처리 안하면 쓰레기값을 가져와 덮어씌움
    for(int j = 1 ; j < i ; j++){
      int temp = dp[j];
      dp[j] = max(temp, before);
      before = temp;
    }//input값이 아니라 dp값을 조작해서 준비시킴

    for(int j = 0 ; j <= i ; j++){
      int input = 0;
      scanf("%d",&input);
      dp[j] += input;
    }

  }
  int answer = dp[0];
  for(int i = 1 ; i < N ; i++){
    answer = max(answer,dp[i]);
  }
  printf("%d",answer);
  free(dp);
  return 0;
}

int max(int a, int b)
{
  return a>b?a:b;
}
