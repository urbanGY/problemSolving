#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long n, t = 0, p = 2;
	scanf("%lld",&n);
	while(true) {
		t++;
		p *= 2;
		if(n <= (t+1)*p-1) {
			printf("%lld",t);
			break;
		}
	}
	return 0;
}
