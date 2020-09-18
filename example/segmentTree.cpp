// 백준 2042 구간 합 구하기 기반 코드
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> seg;
vector<long long> arr;

long long init(int node, int start, int end) {
	if(start == end) return seg[node] = arr[start];
	int mid = (start+end) / 2;
	return seg[node] = init(node*2,start,mid) + init(node*2+1,mid+1,end);
}

long long getSum(int node, int start, int end, int left, int right) {
	if(end < left || start > right) return 0;
	if(left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return getSum(node*2,start,mid,left,right) + getSum(node*2+1,mid+1,end,left,right);
}

long long update(int node, int start, int end, int index, int change) { //아래 리프 노드를 갱신하고 그 위 값을 갱신하는 구조, 다른 풀이에서의 diff 를 갱신하는 방식과 약간 다름
	if(!(start <= index && index <= end)) return seg[node];
	if(start == end) return seg[node] = change;
	int mid = (start+end) / 2;
	return seg[node] = update(node*2,start,mid,index,change) + update(node*2+1,mid+1,end,index,change);
}

int main() {
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	seg = vector<long long>(pow(2,ceil(log2(N))+1));
	arr = vector<long long>(N);
	for(int i = 0 ; i < N ; i++) scanf("%lld",&arr[i]);
	init(1,0,N-1);
	for(int i = 0 ; i < M+K ; i++){
		int a;
		scanf("%d",&a);
		if(a == 1) {
			int b;
			long long c;
			scanf("%d %lld",&b,&c);
			update(1,0,N-1,b-1,c);
		}else if(a == 2) {
			int b, c;
			scanf("%d %d",&b,&c);
			printf("%lld\n",getSum(1,0,N-1,b-1,c-1));
		}
	}
	return 0;
}
