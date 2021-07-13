#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,r,q;
vector<vector<int> > tree;
vector<int> cnt;
void setTree(int cur, int parent) {
	for(auto& sibling : tree[cur]) {
		if(sibling != parent) {
			setTree(sibling,cur);
			cnt[cur] += cnt[sibling];
		}
	}
}
int main() {
	scanf("%d %d %d",&n,&r,&q);
	tree = vector<vector<int> >(n+1);
	cnt = vector<int>(n+1,1);
	for(int i = 0 ; i < n-1 ; i++) {
		int u, v;
		scanf("%d %d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	setTree(r,-1);
	for(int i = 0 ; i < q ; i++) { 
		int query;
		scanf("%d",&query);
		printf("%d\n",cnt[query]);
	}
	return 0;
}