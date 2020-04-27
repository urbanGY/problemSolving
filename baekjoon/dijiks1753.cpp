#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int INF = 987654321;
vector< vector<pair<int, int> > > graph;//first to vertex, second cost
vector<int> ans;
priority_queue<pair<int, int> > pq;//first vertex, second cost

int main(){
  int V, E, start;
  scanf("%d %d %d",&V,&E,&start);
  int from, to, cost;
  graph.resize(V + 1);
  ans.resize(V + 1);
  for(int i = 0 ; i < V+1 ; i++) ans[i] = INF;
  for(int i = 0 ; i < E ; i++){
    scanf("%d %d %d",&from,&to,&cost);
    graph[from].push_back(make_pair(to, cost));
  }
  pq.push(make_pair(start,0));//to vertex1 cost 0
  ans[start] = 0;
  while(!pq.empty()){
    pair<int, int> now = pq.top();
    pq.pop();
    int now_vertex = now.first;
    int now_cost = -1 * now.second;//now_vertex로 오는 cost
    if(now_cost > ans[now_vertex]) continue;
    for(int i = 0 ; i < graph[now_vertex].size() ; i++){
      if(ans[graph[now_vertex][i].first] > ans[now_vertex] + graph[now_vertex][i].second){
        ans[graph[now_vertex][i].first] = ans[now_vertex] + graph[now_vertex][i].second;
        pq.push(make_pair(graph[now_vertex][i].first,-graph[now_vertex][i].second));
      }
    }
  }
  for(int i = 1 ; i <= V ; i++){
    if(ans[i] == INF) printf("INF\n");
    else printf("%d\n",ans[i]);
  }
  return 0;
}
