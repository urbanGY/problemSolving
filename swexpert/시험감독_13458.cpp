#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long answer = 0;
	int n, b, c;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",&v[i]);
	}
	scanf("%d %d",&b, &c);
	for(auto num : v) {
		answer += 1;
		if(num <= b) {
			continue;
		}
		num -= b;
		if(num%c == 0) answer += (num/c);
		else answer += (num/c)+1;
	}
	printf("%lld\n",answer);
	return 0;
}
