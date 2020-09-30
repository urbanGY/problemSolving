#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> node;

int find(int n) {
  if(n == node[n]) return n;
  else return node[n] = find(node[n]);
}

struct Edge{
  int from;
  int to;
  int cost;
};

bool cmp(Edge * a, Edge * b) {
  return a->cost < b->cost;
}

int main() {
  int V, E, answer = 0;
  scanf("%d %d",&V,&E);
  node = vector<int>(V+1);
  vector<Edge *> arr;
  for(int i = 1 ; i <= V ; i++) node[i] = i;
  for(int i = 0 ; i < E ; i++){
    Edge * edge = new Edge();
    scanf("%d %d %d",&edge->from,&edge->to,&edge->cost);
    arr.push_back(edge);
  }
  sort(arr.begin(),arr.end(),cmp);
  for(auto edge : arr) {
    int u = find(edge->from);
    int v = find(edge->to);
    int cost = edge->cost;
    if(u != v) {
      answer += cost;
      node[u] = v;
    }
  }
  printf("%d\n",answer);
  return 0;
}
