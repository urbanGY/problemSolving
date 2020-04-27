#include <iostream>
#include <cmath>
using namespace std;
long long findSqr(long long);

int main() {
	int N = 0;
	cin>>N;
	for(int i = 0 ; i < N ; i++){
		long long x = 0 , y = 0;
		cin>>x>>y;
		long long distance = y-x;
		if(distance == 0){
			cout<<0<<endl;
			continue;
		}
		if(distance == 1){
			cout<<1<<endl;
			continue;
		}
		if(distance == 2){
			cout<<2<<endl;
			continue;
		}
		if(distance == 3 || distance == 4){
			cout<<3<<endl;
			continue;
		}
		long long big = findSqr(distance);
		long long small = big-1;

		long long bigSq = big*big;
		long long smallSq = (big-1)*(big-1);
		long long bound = floor((bigSq-smallSq)/2);
		if(distance >= bigSq-bound){
			cout<<(small*2)+1<<endl;
		}else {
			cout<<small*2<<endl;
		}
	}
	return 0;
}

long long findSqr(long long distance){
	long long i = 1;
	while(i*i < distance){
		i++;
	}
	return i;
}
