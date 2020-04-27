#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  int arr[N];
  for(int i = 0 ; i < N ; i++)
    scanf("%d",&arr[i]);
  sort(arr,arr+N);
  int sum = 0;
  for(int i = 0 ; i < N ; i++){
    for(int j = i ; j >= 0 ; j--)
      sum += arr[j];
  }
  printf("%d",sum);
  return 0;
}
