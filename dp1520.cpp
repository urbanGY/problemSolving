#include <iostream>
using namespace std;

int board[501][501];
int check[501][501];
int N , M;

int find(int i , int j){
  if(i == N-1 && j == M-1) return 1;
  if (check[i][j] == -1){
    check[i][j] = 0;
    if(j+1 < M && board[i][j] > board[i][j+1]){
      check[i][j] += find(i,j+1);
    }
    if(j-1 >= 0 && board[i][j] > board[i][j-1]){
      check[i][j] += find(i, j-1);
    }
    if(i+1 < N && board[i][j] > board[i+1][j]){
      check[i][j] += find(i+1 , j);
    }
    if(i-1 >= 0 && board[i][j] > board[i-1][j]){
      check[i][j] += find(i-1 , j);
    }
  }

  return check[i][j];
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      scanf("%d",&board[i][j]);
      check[i][j] = -1;
    }
  }
  printf("%d",find(0,0));
  return 0;
}
