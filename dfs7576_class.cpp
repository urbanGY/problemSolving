Skip to content

Search or jump to…

Pull requests
Issues
Marketplace
Explore
 @urbanGY Sign out
0
0 0 urbanGY/problemSolving
 Code  Issues 0  Pull requests 0  Projects 0  Wiki  Insights  Settings
problemSolving/dfs7576.cpp
Fetching contributors…

83 lines (77 sloc)  1.41 KB

#include <iostream>
#include <queue>
using namespace std;

class node{
private:
  int x;
  int y;
  int day;
public:
  node(int x, int y, int day)
  :x(x),y(y),day(day)
  {

  }
  int getX(){
    return this->x;
  }
  int getY(){
    return this->y;
  }
  int getDay(){
    return this->day;
  }
};

int main(){
  int M,N;
  scanf("%d %d",&M,&N);
  int board[N][M];
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      scanf("%d",&board[i][j]);
    }
  }
  node *pos;
  queue< node* > Q;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      if(board[i][j] == 1){
        Q.push(new node(i,j,0));
      }
    }
  }
  while(!Q.empty()){
    pos = Q.front();
    int x = pos->getX();
    int y = pos->getY();
    int day = pos->getDay();
    delete pos;
    Q.pop();
    day++;
    board[x][y] = day;

    if(x-1 >= 0 && board[x-1][y] == 0){
      Q.push(new node(x-1,y,day));
    }//북
    if(x+1 < N && board[x+1][y] == 0){
      Q.push(new node(x+1,y,day));
    }//남
    if(y-1 >= 0 && board[x][y-1] == 0){
      Q.push(new node(x,y-1,day));
    }//서
    if(y+1 < M && board[x][y+1] == 0){
      Q.push(new node(x,y+1,day));
    }//동
  }
  int max = 0;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      if(board[i][j] == 0){
        printf("-1");
        return 0;
      }

      if(max < board[i][j])
        max = board[i][j];
    }
  }
  printf("%d",max-1);
  return 0;
}
