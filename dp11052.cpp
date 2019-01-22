#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
  int N = 0;
  scanf("%d",&N);
  int * input = (int *)calloc(N+1,sizeof(int));
  float * value = (float *)calloc(N+1,sizeof(float));
  int * check = (int *)calloc(N+1,sizeof(int));

  for(int i = 1 ; i <= N ; i++){
    scanf("%d",&input[i]);
    value[i] = (float)input[i]/i;
  }
  int remain = N;
  for(int i = 1 ; i <= N ; i++){
    int maxIndex = 0;
    for(int j = 1 ; j <= N ; j++){
      if(value[maxIndex] < value[j])
        maxIndex = j;
    }
    value[maxIndex] = 0.0;
    if(remain < maxIndex) continue;
    int quotient = remain/maxIndex;
    check[maxIndex] = quotient;
    remain = remain%maxIndex;
    if(remain == 0) break;
  }
  int answer = 0;
  for(int i = 1 ; i <= N ; i++){
    if(check[i] != 0){
      int temp = input[i]*check[i];
      answer += temp;
    }
  }
  printf("%d\n",answer);
  //예시 답 및 테스트는 잘 되는데 채점은 틀린다고 나옴 ㅡㅡ
  //테스트 케이스를 못잡겟다
  free(input);
  free(value);
  free(check);
  return 0;
}
