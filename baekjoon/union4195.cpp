#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> node;
vector<int> height;

int find(int n) {
	if(node[n] == -1) return n;
	else return node[n] = find(node[n]);
}

void merge(int u, int v) {
	if(u == v) return;
	int sum = height[u] + height[v];
	node[u] = v;
	height[v] = sum;
	height[u] = sum;
}

int maxVal(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int test_case = 0 ; test_case < T ; test_case++) {
		int n, cnt = 0;
		map<string,int> m; // char배열을 key로 할 때 string으로 맵 선언해도 상관이 없다.
		scanf("%d",&n); // 주어진 N값이 10만을 넘지 않는다고 하는데 이 경우 최악의 입력 시 20만명이 들어오게 된다. 따라서 아래의 노드와 높이를 모두 20만으로 초기화 해줘야 한다.
		node = vector<int>(200010,-1);
		height = vector<int>(200010,1); 
		for(int i = 0 ; i < n ; i++) {
			//string sa, sb;
			char sa[21], sb[21];
			scanf("%s %s",sa,sb);
			if(m.count(sa) == 0) m[sa] = cnt++;
			if(m.count(sb) == 0) m[sb] = cnt++;
			int u = find(m[sa]);
			int v = find(m[sb]);
			merge(u,v);
			printf("%d\n",height[v]); //cout보단 printf로 해야 시간 안터진다.
		}
	}
	return 0;
}