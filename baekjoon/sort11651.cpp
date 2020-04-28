#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
  if(a.second == b.second){
    return a.first < b.first;
  }else {
    return a.second < b.second;
  }
}
int main(){
  int N;
  scanf("%d",&N);
  vector<pair<int, int> > v;
  for(int i = 0 ; i < N ; i++){
    int x , y;
    scanf("%d %d",&x,&y);
    v.push_back(make_pair(x,y));
  }
  sort(v.begin(), v.end(), cmp);
  for(auto a : v){
    printf("%d %d\n",a.first, a.second);
  }
  return 0;
}
