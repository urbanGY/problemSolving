#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
int N, E;

struct cmp {
  bool operator()(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
  }
};

int minVal(int a, int b) { return a < b ? a : b; }

vector<int> dijikstra(vector<vector<int> >& board, int start) {
  vector<int> distance(N+1,987654321);
  priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;
  pq.push(make_pair(start,0));
  distance[start] = 0;
  while(!pq.empty()){
    pair<int,int> pr = pq.top();
    pq.pop();
    int current = pr.first, cost = pr.second;
    if(cost > distance[current]) continue;
    for(int i = 1 ; i <= N ; i++){
      if(board[current][i] != -1) {
        if(board[current][i] + cost < distance[i]) {
          distance[i] = board[current][i] + cost;
          pq.push(make_pair(i,distance[i]));
        }
      }
    }
  }
  return distance;
}

int main() {
  int v1, v2;
  scanf("%d %d",&N,&E);
  vector<vector<int> > board(N+1,vector<int>(N+1,-1));
  vector<vector<int> > val(3);
  for(int i = 0 ; i < E ; i++){
    int from, to, cost;
    scanf("%d %d %d",&from,&to,&cost);
    board[from][to] = cost;
    board[to][from] = cost;
  }
  scanf("%d %d",&v1,&v2);
  val[0] = dijikstra(board,1);
  val[1] = dijikstra(board,v1);
  val[2] = dijikstra(board,v2);
  if(val[0][v1] == 987654321 ||  val[1][v2] == 987654321 || val[2][N] == 987654321) printf("-1\n");
  else {
    int result = minVal(val[0][v1] + val[1][v2] + val[2][N], val[0][v2] + val[2][v1] + val[1][N]);
    printf("%d\n",result);
  }
  return 0;
}
/*
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3
*/
