#include <iostream>
using namespace std;

bool * digits;
int N;
long long int factorial;
int * array;

long long int getFactorial (int);
int getDigits(int);
void findArr(int, long long int);
long long int findSeq(int);

int main(){
   N = 0;
  scanf("%d",&N);
  factorial = getFactorial(N-1);
  array = new int[N+1];
  digits = new bool[N+1];
  digits[0] = false;
  for(int i = 1 ; i <= N ; i++)
    digits[i] = true;

  int problem = 0;
  scanf("%d",&problem);
  if(problem == 1){//k번째 순열 출력
    long long int k = 0;
    scanf("%lld",&k);
    findArr(1,k);// (i-1)*(N-1)! < k < i*(N-1)! , 1 <= i <= N 여기서 k번째 고를 수 있는 수를 가져와 한 자리를 고르고 계속 N-1! 은 N-2!, N-3! ... 1 로 진행시킨다.
    for(int i = 1 ; i <= N ; i++)
      printf("%d ",array[i]);
  }else if(problem == 2) {//순열이 몇번째 인지 출력
    for(int i = 1 ; i <= N ; i++)
      scanf("%d",&array[i]);
    printf("%lld",findSeq(1)+1);
  }
  //big O (N^2)
  delete array;
  delete digits;
  return 0;
}

long long int getFactorial(int n){
  long long int mul = 1;
  for(int i = 1 ; i <= n ; i++)
    mul *= i;
  return mul;
}

int getDigits(int x){//남아있는 선택할 수 있는 수 중 x번째의 수를 반환하고 해당 수에 false로 선택되었음을 표시
  int answer = 0;
  int count = 0;
  for(int i = 1 ; i <= N ; i++){
    if(digits[i])
      count++;
    else
      continue;

    if(count == x){
      digits[i] = false;
      answer = i;
      break;
    }
  }
  return answer;
}

void findArr(int seq, long long int k){
  int x = 0;
  for(int digit = 1 ; digit <= N ; digit++){
    if(k <= digit*factorial){
      x = digit;
      k -= (digit-1)*factorial;
      break;
    }
  }
  array[seq] = getDigits(x);
  if(N != seq){
    factorial /= N-seq; // 0으로 나누면 안댐 오류 없이 걍 끝내버림 ㅡㅡ
    seq++;
    findArr(seq,k);
  }
}

long long int findSeq(int seq){
  if(seq == N) return 0;
  long long int answer = 0;
  int x = 0;
  for(int i = 1 ; i <= N ; i++ ){
    if(digits[i]) x++;
    else continue;
    if(i == array[seq]){
      digits[i] = false;
      answer += (x-1)*factorial;
      break;
    }
  }
  factorial /= N-seq;
  seq++;
  return answer + findSeq(seq);
}
