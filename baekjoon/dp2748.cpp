#include <iostream>
using namespace std;

int main() {
	long long a = 0, b = 1, n, tmp;
	cin >> n;
	if(n == 0) {
		cout<<0<<endl;
		return 0;
	}
	if(n == 1) {
		cout<<1<<endl;
		return 0;
	}
	for(long long i = 2 ; i <= n ; i++){
		tmp = a+b;
		a = b;
		b = tmp;
	}
	cout<<b<<endl;
	return 0;
}
