#include <iostream>
using namespace std;

int main(){
  int N , K;
  scanf("%d %d",&N,&K);
  int array[N];
  for(int i = N-1 ; i >= 0 ; i--){
    scanf("%d",&array[i]);
  }
  int cnt = 0;
  for(int i = 0 ; i < N ; i++){
    if(K == 0 )break;
    if(K >= array[i]){
      int tmp = K/array[i];
      K = K - tmp * array[i];
      cnt += tmp;
    }
  }
  printf("%d",cnt);
}
