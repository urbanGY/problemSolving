#include <iostream>
#include <stdlib.h>
using namespace std;
int max(int, int);

int main(){
  int N = 0;
  scanf("%d",&N);
  int * dp = (int *)calloc(N+1,sizeof(int));
  int * input = (int *)calloc(N+1,sizeof(int));
  for(int i = 0 ; i < 3 ; i++){
    scanf("%d",&input[i]);
  }
  dp[0] = input[0];
  dp[1] = input[0] + input[1];
  dp[2] = max(dp[1],max(input[0] + input[2], input[1] + input[2]));

  for(int i = 3 ; i < N ; i++){
    scanf("%d",&input[i]);
    dp[i] = max(dp[i-1],max(dp[i-3] + input[i-1] + input[i], dp[i-2] + input[i]));
  }
  printf("%d",dp[N-1]);
  free(input);
  free(dp);
  return 0;
}

int max(int a, int b)
{
  return a>b?a:b;
}
