#include <iostream>
using namespace std;

int main(){
  int N = 0;
  scanf("%d",&N);
  int count = 0;
  if(N < 100){
    printf("%d",N);
  }else if(N < 1000){
    int a = 0, b = 0, c = 0;
    for(int i = 100 ; i <= N ; i++){
      a = i/100;
      b = (i%100)/10;
      c = (i%10);
      int l = a-b;
      int r = b-c;
      if(l == r) count++;
    }
    printf("%d",99+count);
  }else{
    printf("144");
  }
  return 0;
}
