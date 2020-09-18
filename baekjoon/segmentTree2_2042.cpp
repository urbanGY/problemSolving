#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> seg;
vector<long long> arr;
long long treeInit(int Node, int start, int end) {
	if(start == end) return seg[Node] = arr[start];
	int mid = (start+end)/2;
	return seg[Node] = treeInit(Node*2,start,mid) + treeInit(Node*2+1,mid+1,end);
}
long long getSum(int Node, int start, int end, int left, int right) {
	if(end < left || start > right) return 0;
	if(left <= start && end <= right) return seg[Node];
	int mid = (start+end)/2;
	return getSum(Node*2,start,mid,left,right) + getSum(Node*2+1,mid+1,end,left,right);
}

void update(int Node, int start, int end, int index, long long diff) {
	if(!(start <= index && index <= end)) return;
	seg[Node] = seg[Node] + diff;
	if(start != end) {
		int mid = (start+end)/2;
		update(Node*2,start,mid,index,diff);
		update(Node*2+1,mid+1,end,index,diff);
	}
}
int main() {
	int N, M, K;
	scanf("%d %d %d",&N,&M,&K);
	seg = vector<long long>(pow(2,(ceil(log2(N))+1)));
	arr = vector<long long>(N,0);
	for(int i = 0 ; i < N ; i++) {
		scanf("%lld",&arr[i]);
	}
	treeInit(1,0,N-1);
	for(int i = 1 ; i <= M+K ; i++){
		long long a;
		scanf("%lld",&a);
		if(a == 1) { // b- > c
			int b;
			long long c;
			scanf("%d %lld",&b,&c);
			long long diff = c - arr[b-1];
			arr[b-1] = c;
			update(1,0,N-1,b-1,diff);
		}else if(a == 2) {
			int b, c;
			scanf("%d %d",&b, &c);
			printf("%lld\n",getSum(1,0,N-1,b-1,c-1));
		}
	}
	return 0;
}
