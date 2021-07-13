#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 기존에 세그먼트 트리에 값을 더하는 거에서 값을 인덱스로 사용해 1씩 더하고 빼는 방식으로 구현
//
vector<int> seg;

void update(int node, int start, int end, int index, int val) {
	if(index < start || index > end) return;
	if(start == end) {
		seg[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	update(node*2,start,mid,index,val);
	update(node*2+1,mid+1,end,index,val);
	seg[node] =seg[node*2] + seg[node*2+1];
}

int find(int node, int start, int end, int k) { //왜 이게 k번째 작음을 보장하는지 잘 모르겠다, 여기 반환 값은 입력으로 왔던 k번째 작은 수다. 
	if(start == end) return start;
	else {
		int mid = (start + end) / 2;
		if(k <= seg[node*2]) return find(node*2,start,mid,k);
		else return find(node*2+1,mid+1,end,k - seg[node*2]); //여기
	}
}

int main() {
	int S;
	scanf("%d",&S);
	seg = vector<int>(pow(2,ceil(log2(2000002))+1)); // 여기
	for(int i = 0 ; i < S ; i++) {
		int x, y;
		scanf("%d %d",&x,&y);
		if(x == 1) { // update
			update(1,1,2000002,y,1);
		}else {
			int pos = find(1,1,2000002,y);
			printf("%d\n",pos);
			update(1,1,2000002,pos,-1);
		}
	}
	return 0;
}
