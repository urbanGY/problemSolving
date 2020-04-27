#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N = 0 , K = 0;
  scanf("%d %d",&N,&K);
  int * array = new int[N];
  for(int i = 0 ; i < N ; i++)
    scanf("%d",&array[i]);
  sort(array,array+N);
  printf("%d",array[K-1]);
  return 0;
}
