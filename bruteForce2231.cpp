#include <iostream>
using namespace std;

int divide_sum(int, int);

int main(){
  int N = 0;
  scanf("%d",&N);
  int d = 1;
  while(N >= d){
    d *= 10;
  }
  for(int i = 1 ; i < N ; i++){
    if(N == divide_sum(i, d)){
      printf("%d",i);
      return 0;
    }
  }
  printf("0");
  return 0;
}

int divide_sum(int x, int D){
  int d = D;
  int sum = x;
  while(d != 1){
    sum += (x%d)/(d/10);
    d /= 10;
  }
  return sum;
}
