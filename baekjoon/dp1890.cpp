#include <iostream>
using namespace std;
int board[101][101];
long long int check[101][101];
int main(){
  int N;
  scanf("%d",&N);
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      scanf("%d",&board[i][j]);
      check[i][j] = 0;
    }
  }
  check[0][0] = 1;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      int val = board[i][j];
      if(val == 0) continue;
      if(j+val < N){
        check[i][j+val] += check[i][j];
      }
      if(i+val < N){
        check[i+val][j] += check[i][j];
      }
    }
  }
  printf("%lld",check[N-1][N-1]);
  return 0;
}
