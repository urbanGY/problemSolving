#include <iostream>
using namespace std;
int max(int, int);

int main(){
  int N = 0;
  scanf("%d",&N);
  int answer = 0;
  int sum = 0;
  int input = 0;

  scanf("%d",&input);
  sum = input;
  answer = input; // N 이 1이고 첫번 째 값이 음수가 나올 경우 answer = max(sum, answer) 이 부분에서 답이 0이 됨으로 첫번 째 케이스는 강제로 값을 input으로 할당해 줘야 한다.

  for(int i = 1 ; i < N ; i++){//카데인 알고리즘
    scanf("%d",&input);
    sum = max(sum + input, input);
    answer = max(sum, answer);
  }
  printf("%d",answer);
  return 0;
}

int max(int a, int b) {
   return a > b ? a : b;
 }
