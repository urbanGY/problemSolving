#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N, M;

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

int getMax(int a, int b) {
	return a > b ? a : b;
}

vector<int> dijikstra(vector<vector<int> >& board, int start) {
	vector<int> distance(N+1,987654321);
	priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;
	pq.push(make_pair(start,0));
	distance[start] = 0;
	while(!pq.empty()) {
		pair<int,int> pr = pq.top();
		pq.pop();
		int current = pr.first, cost = pr.second;
		if(cost > distance[current]) continue;
		for(int i = 1 ; i <= N ; i++) {
			if(board[current][i] != -1 && cost + board[current][i] < distance[i]) {
				distance[i] = cost + board[current][i];
				pq.push(make_pair(i,distance[i]));
			}
		}
	}
	return distance;
}

int main() {
	int a, b, c, answer = 987654321;
	scanf("%d %d",&N,&M);
	vector<vector<int> > board(N+1,vector<int>(N+1,-1));
	vector<vector<int> > distance(3);
	for(int i = 0 ; i < M ; i++){
		int from, to, cost;
		scanf("%d %d %d",&from, &to, &cost);
		board[from][to] = cost;
		board[to][from] = cost;
	}
	scanf("%d %d %d",&a,&b,&c);
	distance[0] = dijikstra(board,a);
	distance[1] = dijikstra(board,b);
	distance[2] = dijikstra(board,c);
	for(int i = 1 ; i <= N ; i++) {
		int maxVal = getMax(distance[0][i],getMax(distance[1][i],distance[2][i]));
		if(maxVal < answer) answer = maxVal;
	}
	printf("%d",answer);
	return 0;
}
