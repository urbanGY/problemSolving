#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k;

struct cmp {
  bool operator()(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
  }
};

bool cmpSort(int a, int b) {
  return a < b;
}

vector<int> dijikstra(vector<vector<int> >& board, int start) {
  vector<int> distance(n+1,987654321);
  priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;
  pq.push(make_pair(start,0));
  distance[start] = 0;
  while(!pq.empty()) {
    pair<int,int> pr = pq.top();
    pq.pop();
    int current = pr.first, cost = pr.second;
    if(cost > distance[current]) continue;
    for(int i = 1 ; i <= n ; i++) {
      if(board[current][i] != -1 && board[current][i] + cost < distance[i]) {
        distance[i] = board[current][i] + cost;
        pq.push(make_pair(i,distance[i]));
      }
    }
  }
  return distance;
}

int main() {
  scanf("%d %d %d",&n,&m,&k);
  vector<vector<int> > distance(n+1);
  vector<vector<int> > board(n+1,vector<int>(n+1,-1));
  for(int i = 0 ; i < m ; i++) {
    int from, to, cost;
    scanf("%d %d %d",&from,&to,&cost);
    board[from][to] = cost;
  }
  for(int i = 1 ; i <= n ; i++) {
    distance[i] = dijikstra(board,i);
  }
  for(int i = 1 ; i <= n ; i++) {
    vector<int> candidate;
    for(int j = 1 ; j <= n ; j++) {
      if(!(distance[1][j] == 987654321 || distance[j][i] == 987654321)) {
        candidate.push_back(distance[1][j] + distance[j][i]);
      }
    }
    if(candidate.size() < k) printf("-1\n");
    else {
      sort(candidate.begin(),candidate.end(),cmpSort);
      for(auto elem : candidate) {
        printf("%d ",elem);
      }
      printf("\n");
      // printf("%d\n",candidate[k-1]);
    }
  } 

  return 0;
}
/*
5 10 2
1 2 2
1 3 7
1 4 5
1 5 6
2 4 2
2 3 4
3 4 6
3 5 8
5 2 4
5 4 1
*/
