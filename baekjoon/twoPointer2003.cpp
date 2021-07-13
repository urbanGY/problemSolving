#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long answer = 0;
	int i = 0, j = 0;
	long long n, m;
	long long sum = 0;
	scanf("%lld %lld",&n,&m);
	vector<int> arr(n,0);
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",&arr[i]);
	}
	while(true) {
		if(sum <= m) {
			if(i < n) {
				sum += arr[i];
				i++;
			}else {
				if(j == n) break;
				sum -= arr[j];
				j++;
			}
		}else {
			if(j == n) break;
			if(j < n) {
				sum -= arr[j];
				j++;
			}
		}
		if(sum == m) answer++;
	}
	printf("%lld",answer);
	return 0;
}
