#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a.second > b.second;
	}
};

int minval(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int N, M, a,b, answer = 0;
	scanf("%d %d",&N,&M);
	vector<vector<int> > board(N+1,vector<int>(N+1,-1));
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
	vector<bool> visited(N+1,false);
	vector<int> distance(N+1, 987654321);
	for(int i = 1 ; i <= M ; i++){
		int from,to,weight;
		scanf("%d %d %d",&from,&to,&weight);
		if(board[from][to] != -1) {
			if(board[from][to] > weight){
				board[from][to] = weight;
			}
		}else {
			board[from][to] = weight;
		}
	}
	scanf("%d %d",&a,&b);
	pq.push(make_pair(a,0));
	while(!pq.empty()) {
		pair<int, int> pos = pq.top();
		pq.pop();
		int current = pos.first, weight = pos.second;
		if(visited[current]) continue;
		visited[current] = true;
		for(int i = 1 ; i <= N ; i++) {
			if(board[current][i] != -1) {
				distance[i] = minval(distance[i],weight + board[current][i]);
				pq.push(make_pair(i,distance[i]));
			}
		}
	}
	cout<<distance[b]<<endl;
	return 0;
}
