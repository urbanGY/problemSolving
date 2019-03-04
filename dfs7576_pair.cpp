#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
  int M,N;
  scanf("%d %d",&M,&N);
  int board[N][M];
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      scanf("%d",&board[i][j]);
    }
  }
  pair<int, int> pos;
  queue< pair<int,int> > Q;


  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      if(board[i][j] == 1){
        Q.push(make_pair(i,j));
        Q.push(make_pair(0,0));
      }
    }
  }
  while(!Q.empty()){
    pos = Q.front();
    Q.pop();
    int x = pos.first;
    int y = pos.second;

    pos = Q.front();
    Q.pop();
    int day = pos.first;

    day++;
    board[x][y] = day;

    if(x-1 >= 0 && board[x-1][y] == 0){
      Q.push(make_pair(x-1,y));
      Q.push(make_pair(day,0));
    }//북
    if(x+1 < N && board[x+1][y] == 0){
      Q.push(make_pair(x+1,y));
      Q.push(make_pair(day,0));
    }//남
    if(y-1 >= 0 && board[x][y-1] == 0){
      Q.push(make_pair(x,y-1));
      Q.push(make_pair(day,0));
    }//서
      Q.push(make_pair(x,y+1));
      if(y+1 < M && board[x][y+1] == 0){
      Q.push(make_pair(day,0));
    }//동
  }
  int max = 0;
  bool zero = false;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      if(board[i][j] == 0)
        zero = true;
      if(max < board[i][j])
        max = board[i][j];
    }
  }
  if(zero){
    printf("-1");
  }else {
    printf("%d",max-1);
  }
  return 0;
}
