#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<vector<int> > v(21,vector<int>(21,0));
int answer = 2147483647;


void find(vector<bool>& check, string pick, int N, int start){
  if(pick.size() == N/2){
        string other = "";
        for(int i = 1 ; i <= N ; i++)
          if(!check[i])
            other += i+'0';
        int val_a = 0, val_b = 0;
        for(int i = 0 ; i < N/2 ; i++){
          for(int j = i+1 ; j < N/2 ; j++){
            val_a += v[pick[i]-'0'][pick[j]-'0'] + v[pick[j]-'0'][pick[i]-'0'];
            val_b += v[other[i]-'0'][other[j]-'0'] + v[other[j]-'0'][other[i]-'0'];
          }
        }
        int tmp = abs(val_a - val_b);
        if(tmp < answer) answer = tmp;
        return;
  }

  for(int i = start ; i <= N ; i++){
    check[i] = true;
    find(check, pick + to_string(i), N, i+1);
    check[i] = false;
  }
}

int main(){
  int N;
  cin >> N;
  string s = "";
  vector<bool> check(N+1, false);

  for(int i = 1 ; i <= N ; i++)
    for(int j = 1 ; j <= N ; j++)
      scanf("%d",&v[i][j]);

  find(check,s,N,1);
  cout<<answer<<endl;
  return 0;
}
