#include <iostream>
using namespace std;

int board[501][501];
int check[501][501];
int N;

int max(int a, int b){
  if(a > b) return a;
  else return b;
}

int find(int i, int j){
  if((board[i-1][j] < board[i][j] || i-1 < 0)  && (board[i+1][j] < board[i][j] || i+1 >= N) && (board[i][j-1] < board[i][j] || j-1 < 0) && (board[i][j+1] < board[i][j] || j+1 >= N))
    return 1;
  if(check[i][j] == -1){
    int a = 0 , b = 0 , c = 0 , d = 0;
    check[i][j] = 0;
    if(j+1 < N && board[i][j] < board[i][j+1]){
      a = find(i,j+1);
    }
    if(j-1 >= 0 && board[i][j] < board[i][j-1]){
      b = find(i,j-1);
    }
    if(i+1 < N && board[i][j] < board[i+1][j]){
      c = find(i+1,j);
    }
    if(i-1 >= 0 && board[i][j] < board[i-1][j]){
      d = find(i-1,j);
    }
    check[i][j] = max(max(max(a,b),c),d) + 1;
  }

  return check[i][j];
}

int main(){
  scanf("%d",&N);
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      scanf("%d",&board[i][j]);
      check[i][j] = -1;
    }
  }
  int max = -1;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      int ans = find(i,j);
      if(max < ans) max = ans;
    }
  }
  printf("%d",max);
  return 0;
}
