#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K,N, start = 1, end = 1000000;
  int len = 0;
  scanf("%d %d",&K,&N);
  vector<int> arr(K);
  for(int i = 0 ; i < K ; i++){
    scanf("%d",&arr[i]);
  }
  while(start <= end) {
    int mid = (start + end) / 2;
    int sum = 0;
    for(int i = 0 ; i < K ; i++) sum += (arr[i]/mid);
    if(sum >= N) {
      if(mid > len) {
        len = mid;
      }
      start = mid+1;
    }else {
      end = mid-1;
    }
  }
  printf("%d\n",len);
  return 0;
}
/*
4 11
802
743
457
539
*/
