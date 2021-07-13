#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> node;

int find(int n) {
  if(n == node[n]) return n;
  else return node[n] = find(node[n]);
}

int main() {
  int T;
  scanf("%d",&T);
  for(int t = 0 ; t < T ; t++) {
      int N, M, cnt = 0;
      scanf("%d %d",&N,&M);
      node = vector<int>(N+1);
      for(int i = 1 ; i <= N ; i++) node[i] = i;
      for(int i = 0 ; i < M ; i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        int from = find(a), to = find(b);
        if(from != to) {
          cnt++;
          node[from] = to;
        }
      }
      printf("%d\n",cnt);
  }
  return 0;
}
/*
2
3 3
1 2
2 3
1 3
5 4
2 1
2 3
4 3
4 5
*/
