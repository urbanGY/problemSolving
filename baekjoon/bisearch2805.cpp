#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N,M,start = 0, end = 2000000000;
  long long height = 0;
  scanf("%lld %lld",&N,&M);
  vector<long long> arr(N);
  for(int i = 0 ; i < N ; i++) scanf("%lld",&arr[i]);
  while(start <= end) {
    long long mid = (start + end) / 2;
    long long sum = 0;
    for(int i = 0 ; i < N ; i++) {
      if(arr[i] - mid > 0) sum += (arr[i] - mid); //여기서 sum이 21억을 넘을 수 있음
    }
    if(sum >= M) {
      if(mid > height) height = mid;
      start = mid + 1;
    }else {
      end = mid - 1;
    }
  }
  printf("%lld\n",height);
  return 0;
}
