#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N,M;
vector<int> node;

int find(int n) {
  if(n == node[n]) return n;
  else return node[n] = find(node[n]);
}

int main() {
  map<int,bool> m;
  scanf("%d %d",&N,&M);
  node = vector<int>(N+1);
  for(int i = 1 ; i <= N ; i++) node[i] = i;

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      int input;
      scanf("%d",&input);
      if(input == 1) {
        int u = find(i);
        int v = find(j);
        if(u != v) {
          node[u] = v;
        }
      }
    }
  }
  for(int i = 0 ; i < M ; i++){
    int v;
    scanf("%d",&v);
    m[find(v)] = true; //위의 유니온이 수행되었다고 해도 모든 노드의 부모가 갱신되었으리란 보장이 없음.
  }
  if(m.size() == 1) printf("YES\n");
  else printf("NO\n");
  return 0;
}
