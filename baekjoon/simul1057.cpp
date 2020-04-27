#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
  int N = 0, jimin = 0, hansu = 0;
  scanf("%d %d %d",&N,&jimin,&hansu);
  int * array = (int *)calloc(N+1,sizeof(int));
  array[jimin] = 1;
  array[hansu] = 1;
  int round = 0;
  if(N%2 == 1)
    N += 1;
  while(N != 1){
    round++;
    for(int i = 2 ; i <= N ; i += 2){
      if(array[i - 1] == 1 && array[i] == 1){
        printf("%d",round);
        delete [] array;
        return 0;
      }else if(array[i - 1] == 1){
        array[i - 1] = 0;
        array[(i-1)/2+1] =1;
      }else if(array[i] == 1){
        array[i] = 0;
        array[i/2] = 1;
      }
    }
    N = N/2;
    if(N%2 == 1)
      N += 1;
  }
  delete [] array;
  printf("-1");
  return 0;
}
