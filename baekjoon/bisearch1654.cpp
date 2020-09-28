#include <iostream>
#include <vector>
#include <climits> //최대 수 사용하기 위한 라이브러리
using namespace std;

int main() {
  long long K,N, start = 1, end = LLONG_MAX-1; //랜선의 최대 길이 조건에 맞추기 위해서
  long long len = 0;
  scanf("%lld %lld",&K,&N);
  vector<long long> arr(K);
  for(int i = 0 ; i < K ; i++){
    scanf("%lld",&arr[i]);
  }
  while(start <= end) {
    long long mid = (start + end) / 2;
    long long sum = 0;
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
  printf("%lld\n",len);
  return 0;
}
