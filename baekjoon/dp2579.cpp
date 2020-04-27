#include <iostream>
#include <stdlib.h>
using namespace std;
int max(int , int);
int main(){
  int N;
  scanf("%d",&N);
  int * input = (int *)calloc(N+1,sizeof(int));
  int * dp = (int *)calloc(N+1,sizeof(int));
  for(int i = 1 ; i <= N ; i++){
    scanf("%d",&input[i]);
  }
  dp[1] = input[1];
  dp[2] = input[1] + input[2];
  dp[3] = max(input[1]+input[3],input[2]+input[3]);
  for(int i = 4 ; i <= N ; i++){
    dp[i] = max(dp[i-2]+input[i],dp[i-3]+input[i-1]+input[i]);
  }
  printf("%d",dp[N]);
  free(input);
  free(dp);
  return 0;
}

int max(int a, int b)
{
  if(a > b)
    return a;
  else
    return b;
}
