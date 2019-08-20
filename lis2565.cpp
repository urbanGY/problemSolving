#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int , int> a, pair<int, int> b){
  return a.first < b.first;
}
vector<pair <int, int > > input;
vector<int> dp;
int main(){
  int N;
  scanf("%d",&N);
  for(int i = 0 ; i < N ; i++){
    int a, b;
    scanf("%d %d",&a,&b);
    input.push_back(make_pair(a,b));
    dp.push_back(1);
  }
  sort(input.begin(), input.end(), cmp);
  for(int i = 1 ; i < N ; i++){
    for(int start = i-1 ; start >= 0 ; start--){
      if(input[i].second > input[start].second){
        dp[i] = max(dp[i],dp[start] + 1);
      }
    }
  }

  int ans = -1;
  for(int i = 0 ; i < N ; i++){
    if(dp[i] > ans) ans = dp[i];
  }
  printf("%d",N-ans);
  return 0;
}
