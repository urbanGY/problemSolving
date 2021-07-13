#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N,M,start = 1, end = 1000000000;
  int height = 0;
  scanf("%d %d",&N,&M);
  vector<int> arr(N);
  for(int i = 0 ; i < N ; i++) scanf("%d",&arr[i]);
  while(start <= end) {
    int mid = (start + end) / 2;
    int sum = 0;
    for(int i = 0 ; i < N ; i++) {
      if(arr[i] - mid > 0) sum += (arr[i] - mid);
    }
    if(sum >= M) {
      if(mid > height) height = mid;
      start = mid + 1;
    }else {
      end = mid - 1;
    }
  }
  printf("%d\n",height);
  return 0;
}
/*
4 7
20 15 10 17
*/
