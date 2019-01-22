#include <iostream>
using namespace std;

int main(){
  int N = 0;
  scanf("%d",&N);
  int a = 1;
  int b = 3;
  for(int i = 2 ; i <= N ; i++){
    int temp = ((2*a) + b)%10007;
    a = b;
    b = temp;
  }
  printf("%d",a);
  return 0;
}
