#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

long long mod = 1000000007;
vector<long long> seg;
vector<long long> arr;

long long init(int Node, int start, int end) {
	if(start == end) return seg[Node] = arr[start];
	int mid = (start + end) / 2;
	return seg[Node] = ( (init(Node*2,start,mid)%mod) * (init(Node*2+1,mid+1,end)%mod) )%mod;
}
long long getMul(int Node, int start, int end, int left, int right) {
	if(end < left || start > right) return 1;
	if(left <= start && end <= right) return seg[Node];
	int mid = (start + end) / 2;
	return ( (getMul(Node*2,start,mid,left,right)%mod) * (getMul(Node*2+1,mid+1,end,left,right)%mod) )%mod;
}
long long update(int Node, int start, int end, int index, long long change) {
	if(!(start <= index && index <= end)) return seg[Node];
	if(start == end)
		return seg[Node] = change;
	int mid = (start + end) / 2;
	return seg[Node] = (update(Node*2,start,mid,index,change) * update(Node*2+1,mid+1,end,index,change) )%mod;


}

int main() {
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	seg = vector<long long>(pow(2,ceil(log2(N))+1));
	arr = vector<long long>(N,0);
	for(int i = 0 ; i < N ; i++){
		scanf("%lld",&arr[i]);
	}
	init(1,0,N-1);
	for(int i = 0 ; i < M+K ; i++){
		int a;
		scanf("%d",&a);
		if(a == 1) { // b -> c
			int b;
			long long c;
			scanf("%d %lld",&b,&c);
			update(1,0,N-1,b-1,c);
		}else if(a == 2) {
			int b, c;
			scanf("%d %d",&b,&c);
			printf("%lld\n",getMul(1,0,N-1,b-1,c-1)%mod);
		}
	}
	return 0;
}
