#include <iostream>
#include <vector>
using namespace std;
//백준 1717 집합의 표현 문제가 예시
vector<int> node;

int find(int n) {
  if(n == node[n]) return n;
  else return node[n] = find(node[n]);
}

void merge(int a, int b) {
  int u = find(a);
  int v = find(b);
  if(u != v) node[u] = v;
}

int main() {
  int n,m;
  scanf("%d %d",&n,&m);
  node = vector<int>(n+1);
  for(int i = 1 ; i <= n ; i++) node[i] = i;
  for(int i = 0 ; i < m ; i++){
    int q,a,b;
    scanf("%d %d %d",&q,&a,&b);
    if(q == 0) {
      merge(a,b);
    }else if(q == 1) {
      if(find(a) == find(b)) printf("YES\n");
      else printf("NO\n");
    }
  }
  return 0;
}
