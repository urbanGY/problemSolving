#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n, m, k;

struct pq_cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

struct dist_cmp {
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {
	scanf("%d %d %d",&n,&m,&k);
	vector<vector<int> > board(n+1,vector<int>(n+1,-1));
	priority_queue<pair<int,int>, vector<pair<int,int> >, pq_cmp> pq;
	vector<priority_queue<int, vector<int>, dist_cmp> > distance(n+1);
	for(int i = 0 ; i < m ; i++) {
		int from, to, cost;
		scanf("%d %d %d",&from, &to, &cost);
		board[from][to] = cost;
	}
	pq.push(make_pair(1,0));
	distance[1].push(0);
	while(!pq.empty()) {
		pair<int,int> pr = pq.top();
		pq.pop();
		int current = pr.first, cost = pr.second;
		if(distance[current].size() >= k && cost > distance[current].top()) continue;
		for(int i = 1 ; i <= n ; i++) {
			if(board[current][i] != -1) {
				if(distance[i].size() < k) {
					distance[i].push(cost+board[current][i]);
					pq.push(make_pair(i,cost+board[current][i]));
				}else if(cost+board[current][i] < distance[i].top()) {
					distance[i].pop();
					distance[i].push(cost+board[current][i]);
					pq.push(make_pair(i,cost+board[current][i]));
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; i++) {
		if(distance[i].size() < k) printf("-1\n");
		else {
			printf("%d\n",distance[i].top());
		}
	}
	return 0;
}
