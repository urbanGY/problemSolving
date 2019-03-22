#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){ return a > b; }

int main(){
  int N;
  scanf("%d",&N);
  int arr[N];
  for(int i = 0 ; i < N ; i++)
    scanf("%d",&arr[i]);
  sort(arr,arr+N,cmp);
  int max = 0;
  for(int i = 0 ; i < N ; i++){
    int tmp = arr[i]*(i+1);
    if(max < tmp) max = tmp;
  }
  printf("%d",max);
  return 0;
}
