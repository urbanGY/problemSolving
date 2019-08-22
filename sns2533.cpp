#include <iostream>
#include <queue>
#include <utility>
using namespace std;


int main(){
  int N;
  scanf("%d",&N);
  queue <pair<int, int > > q;
  queue <pair<int, int > > q1;
  for(int i = 0 ; i < N-1 ; i++){
    int a, b;
    scanf("%d %d",&a,&b);
    if(i == 0){
      q1.push(make_pair(a,1));
    }
    q.push(make_pair(a,b));
  }

  int odd = 1 , even = 0;
  while(!q1.empty()){
    pair<int, int> n = q1.front();
    q1.pop();
    int num, level;
    num = n.first;
    level = n.second;
    while(!q.empty()){
      pair<int, int> node = q.front();
      int parent = node.first;
      int child = node.second;
      if(num != parent) break;
      q.pop();
      if(level == 1){
        q1.push(make_pair(child,2));
        even++;
      }else {
        q1.push(make_pair(child,1));
        odd++;
      }
    }
  }
  printf("%d",odd<even?odd:even);
  return 0;
}
