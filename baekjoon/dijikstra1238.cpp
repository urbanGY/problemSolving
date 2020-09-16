#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N=0,M=0,X=0;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int minval(int a, int b) {
	return a < b ? a : b;
}

void dijik(int start, vector<vector<int> >& distance, vector<vector<int> >& board) {
	priority_queue<pair<int, int>, vector<pair<int, int> >,cmp> pq;
	vector<bool> visited(N+1,false);
	pq.push(make_pair(start,0));
	distance[start][start] = 0;
	while(!pq.empty()) {
		pair<int, int> pos = pq.top();
		pq.pop();
		int current = pos.first, weight = pos.second;
		if(visited[current]) continue;
		visited[current] = true;
		for(int i = 1 ; i <= N ; i++){
			if(board[current][i] != -1) {
				distance[start][i] = minval(distance[start][i],weight + board[current][i]);
				pq.push(make_pair(i,distance[start][i]));
			}
		}
	}
}

int main() {
	int max = -1;
	scanf("%d %d %d",&N,&M,&X);
	vector<vector<int> > board(N+1, vector<int>(N+1,-1));
	vector<vector<int> > distance(N+1,vector<int>(N+1,987654321));
	for(int i = 0 ; i < M ; i++) {
		int from, to, weight;
		scanf("%d %d %d",&from,&to,&weight);
		if(board[from][to] != -1) {
			if(board[from][to] > weight) board[from][to] = weight;
		}else {
			board[from][to] = weight;
		}
	}
	for(int i = 1 ; i <= N ; i++){
		dijik(i,distance,board);
	}

	for(int i = 1 ; i <= N ; i++){
		int tmp = distance[i][X] + distance[X][i];
		if(max < tmp) max = tmp;
	}
	cout<<max<<endl;
	return 0;
}
