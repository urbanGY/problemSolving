#include <iostream>
#include <stdlib.h>
using namespace std;
int max(int, int);

int main(){
  int N = 0;
  scanf("%d",&N);
  int * input = (int *)calloc(N+1,sizeof(int));
  int * dp = (int *)calloc(N+1,sizeof(int));
  for(int i = 1 ; i <= N ; i++){
    scanf("%d",&input[i]);
  }
  for(int start = 1 ; start <= N ; start++){
    for(int i = start - 1 ; i >= 0 ; i--){
      if(input[start] > input[i])
        dp[start] = max(dp[start],dp[i] + 1);
    }
  }
  int answer = 0;
  for(int i = 1 ; i <= N ; i++)
    answer = max(dp[i],answer);
  printf("%d",answer);
  return 0;
}

int max(int a, int b){
  return a>b?a:b;
}
