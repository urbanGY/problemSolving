#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
  return a<b;
}
int main(){
  int N;
  int * arr;
  scanf("%d", &N);
  arr = new int[N];
  for(int i = 0 ; i < N ; i++){
    scanf("%d",&arr[i]);
  }
  sort(arr,arr+N,cmp);
  for(int i = 0 ; i < N ; i++){
    printf("%d\n",arr[i]);
  }
  free(arr);
  return 0;
}
