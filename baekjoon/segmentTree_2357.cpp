#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;

int minDummy = 1000000001;
int maxDummy = -1;

vector<pair<int,int> > seg;
vector<int> arr;

int minVal(int a, int b) { return a < b ? a : b; }
int maxVal(int a, int b) { return a > b ? a : b; }

//first 작은거 , second 큰거
pair<int, int> init(int node, int start, int end) {
	if(start == end) {
		seg[node].first = arr[start];
		seg[node].second = arr[end];
		return seg[node];
	}
	int mid = (start + end) / 2;
	pair<int, int> left = init(node*2,start,mid);
	pair<int, int> right = init(node*2+1,mid+1,end);
	seg[node].first = minVal(left.first,right.first);
	seg[node].second = maxVal(left.second,right.second);
	return seg[node];
}

pair<int, int> find(int node, int start, int end, int left, int right) {
	if(end < left || right < start) return make_pair(minDummy,maxDummy);
	if(left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	pair<int, int> leftPair = find(node*2,start,mid,left,right);
	pair<int, int> rightPair = find(node*2+1,mid+1,end,left,right);
	return make_pair(minVal(leftPair.first,rightPair.first),maxVal(leftPair.second,rightPair.second));
}

int main() {
	int N, M;
	scanf("%d %d",&N,&M);
	seg = vector<pair<int,int> >(pow(2,ceil(log2(N))+1),make_pair(minDummy,maxDummy));
	arr = vector<int> (N,0);
	for(int i = 0 ; i < N ; i++) scanf("%d",&arr[i]);
	init(1,0,N-1);
	for(int i = 0 ; i < M ; i++) {
		int a, b;
		scanf("%d %d",&a,&b);
		pair<int,int> result = find(1,0,N-1,a-1,b-1);
		printf("%d %d\n",result.first,result.second);
	}

	return 0;
}
