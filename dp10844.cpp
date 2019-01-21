#include <iostream>
using namespace std;

int main(){
  int N = 0;
  scanf("%d",&N);
  long long int array[10] = {0};
  long long int temp[10] = {0};
  for(int i = 1 ; i < 10 ; i++)
    array[i] = 1;

  for(int i = 1 ; i < N ; i++){
    temp[1] += (array[0] % 1000000000);
    for(int n = 1 ; n < 9 ; n++){
      temp[n-1] += (array[n] % 1000000000);
      temp[n+1] += (array[n] % 1000000000);
    }
    temp[8] += (array[9] % 1000000000);//각 자리수의 마지막을 단위로 값을 누적시킨다.
    for(int n = 0 ; n < 10 ; n++){
      array[n] = temp[n];
      temp[n] = 0;
    }
  }
  long long int answer = 0;//%큰 수가 아니면 오버플로 일어날 수 있으
  for(int i = 0 ; i < 10 ; i++){
    answer += array[i];
  }
  printf("%lld",answer%1000000000);//%1000000000을 붙여야 하는게 매우 추잡함
  return 0;
}
