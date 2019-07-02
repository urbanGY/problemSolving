#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
  int N, sum = 0;
  scanf("%d",&N);
  vector< pair<int, int> > vec;
  for(int i = 0 ; i < N ; i++){
    int input;
    scanf("%d",&input);
    sum += input;
    vec.push_back(make_pair(input,0));
  }
  sort(vec.begin(), vec.end(), cmp);
  pair<int, int> max = make_pair(0,0);
  for(int i = 1 ; i < N ; i++){
    if(vec[i].first == vec[i-1].first){
      vec[i].second = vec[i-1].second + 1;
      if(vec[i].second > max.second){
        max.second = vec[i].second;
        max.first = vec[i].first;
      }
    }
  }
  vector< pair<int, int> > list;
  for(int i = 0 ; i < N ; i++){
    if(vec[i].second == max.second){
      list.push_back(vec[i]);
    }
  }

  int answer;
  if(list.size() == 1){
    answer = list[0].first;
  }else {
    answer = list[1].first;
  }

  printf("%.0f\n",floor((float)sum/N+0.5));
  printf("%d\n",vec[N/2].first);
  printf("%d\n",answer);
  printf("%d\n",vec[N-1].first-vec[0].first);
  return 0;
}
