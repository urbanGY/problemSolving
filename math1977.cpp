#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int M = 0, N = 0;
  scanf("%d %d",&M,&N);
  float a = ceil(sqrt((double)M));
  float b = sqrt((double)N);
  M = (int)a;
  N = (int)b;
  int sum = 0;
  int least = 0;
  for(int i = M ; i <= N ; i++ ){
    sum += i*i;
    if(i == M)
      least = sum;
  }
  if(sum == 0){
    printf("-1");
  }else {
    printf("%d\n",sum);
    printf("%d\n",least);
  }
  return 0;
}
