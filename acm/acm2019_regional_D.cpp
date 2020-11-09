#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node {
	int num;
	int depth;
	int id;
	node(int num, int depth, int id)
	:num(num), depth(depth), id(id) {}
};

bool cmp(node a, node b) {
	return a.depth < b.depth;
}

vector<int> laneSet(int n) {
	vector<int> lane = vector<int>(n);
	for(int i = 0 ; i < n ; i++) lane[i] = i;
	return lane;
}

int main() {
	int n;
	scanf("%d",&n);
	vector<node> info;
	for(int i = 0 ; i < n-1 ; i++) {
		int input, id = 0;
		while(true) {
			id++;
			scanf("%d",&input);
			if(input == 0) break;
			info.push_back(node(i,input,id));
		}
	}
	sort(info.begin(), info.end(), cmp);
	vector<bool> check(info.size(),true);
	int remove = 0;
	while(true) {
		map<pair<int,int>, vector<int>> m;
		vector<int> lane = laneSet(n);
		bool flag = true;
		//cout<<endl;
		for(int i = 0 ; i < info.size() ; i++) {
			if(!check[i]) continue;
			int num = info[i].num;
			int a = lane[num], b = lane[num+1];
			// cout<<a<<" , "<<b<<endl;
			if(!m[{b,a}].empty()) {
				remove += 2;
				int idx = m[{b,a}].back();
				check[idx] = false;
				check[i] = false;
				flag = false;
				break;
			}
			m[{a,b}].push_back(i);
			lane[num] = b;
			lane[num+1] = a;
		}
		if(flag) break;
	}
	printf("%d\n",info.size() - remove);
	for(int i = 0 ; i < info.size() ; i++) {
		if(check[i]) {
			printf("%d %d\n",info[i].num+1, info[i].id);
		}
	}
	return 0;
}
