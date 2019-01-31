#include <iostream>
using namespace std;
int constant(int);
void getAnswer(int, int);//x, L

int main(){
  int N = 0 , L = 0;
  scanf("%d %d",&N,&L);
  int c = constant(L);
  while(L <= 100){
    int purpose = N - c;
    if((purpose%L == 0) && (purpose/L >= 0)){//문제의 조건이 음이 아닌 정수의 수열임으로 0도 포함되어 나와야 한다!
      getAnswer(purpose/L,L);
      return 0;
    }else {
      c += L;
      L++;
    }
  }
  printf("-1");
  return 0;
}

int constant(int input){
  int sum = 0;
  for(int i = 1 ; i < input ; i++){
    sum += i;
  }
  return sum;
}

void getAnswer(int x, int L){
  for(int i = 0 ; i < L-1 ; i++){
    printf("%d ",x+i);
  }
  printf("%d",x+L-1);
}

// int guess = 0;
// int b = constant(L);
// while(L <= 100){
//   for(int x = 1 ; x < N ; x++){
//     guess = L*x + b; // 방정식을 세우고 x값을 반복문으로 맞추는것은 너무 많은 시간을 소비한다
//     if(N == guess){  // 개선한 위의 답처럼 같은 결과를 수학적 수식으로 정리해 더 빠르게 바꿀 수 있따.
//       getAnswer(x, L);
//       return 0;
//     }else if(guess > N){
//       break;
//     }
//   }
//   b += L;
//   L++;
// }
