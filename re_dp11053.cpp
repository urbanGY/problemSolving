#include <iostream>
using namespace std;

int max(int a, int b){
  return a>b?a:b;
}

int input[1001];
int dp[1001];

int main(){
  int N;

  scanf("%d",&N);
  for(int i = 0 ; i < N ; i++)
    scanf("%d",&input[i]);

  for(int i = 1 ; i < N ; i++){
    for(int start = i - 1 ; start >= 0 ; start--){
      if(input[i] > input[start]){
        dp[i] = max(dp[i], dp[start] + 1);
      }
    }
  }
  int ans = -1;
  for(int i = 0 ; i < N ; i++){
    if(dp[i] > ans) ans = dp[i];
  }
  printf("%d",ans+1);
  return 0;
}
