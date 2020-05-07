#include <iostream>
using namespace std;

int main() {
	int n, a = 1, b = 2, tmp;
	cin >> n;
	if(n == 1) {
		cout<<1<<endl;
		return 0;
	}
	if(n == 2) {
		cout<<2<<endl;
		return 0;
	}
	for(int i = 3 ; i <= n ; i++){
		tmp = (a + b)%15746;
		a = b;
		b = tmp;
	}
	cout<<b<<endl;
	return 0;
}
