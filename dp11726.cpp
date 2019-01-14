#include <iostream>
using namespace std;

int main(){
  int a = 1;
  int b = 2;
  int n = 0;
  scanf("%d",&n);
  for(int i = 1 ; i < n ; i++){
    int temp = (a + b)%10007;
    a = b;
    b = temp;
  }
  printf("%d",a);
  return 0;
}
