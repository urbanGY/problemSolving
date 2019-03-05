#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct Node{
  int x;
  int y;
  int day;
}Node;

int board[1003][1003];
queue< Node* > Q;

int main(){
  int M,N, max = 0;
  scanf("%d %d",&M,&N);
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      scanf("%d",&board[i][j]);
      if(board[i][j] == 1){
        Node * node = (Node*)malloc(sizeof(Node));
        node->x = i;
        node->y = j;
        node->day = 1;
        Q.push(node);
      }
    }
  }
  Node *pos;
  while(!Q.empty()){
    pos = Q.front();
    Q.pop();
    int x = pos->x;
    int y = pos->y;
    int day = pos->day;
    free(pos);
    if(max < day) max = day;

    if(x-1 >= 0 && board[x-1][y] == 0){
      board[x-1][y] = day + 1;
      Node * node = (Node*)malloc(sizeof(Node));
      node->x = x-1;
      node->y = y;
      node->day = day+1;
      Q.push(node);
    }//북
    if(x+1 < N && board[x+1][y] == 0){
      board[x+1][y] = day + 1;
      Node * node = (Node*)malloc(sizeof(Node));
      node->x = x+1;
      node->y = y;
      node->day = day+1;
      Q.push(node);
    }//남
    if(y-1 >= 0 && board[x][y-1] == 0){
      board[x][y-1] = day + 1;
      Node * node = (Node*)malloc(sizeof(Node));
      node->x = x;
      node->y = y-1;
      node->day = day+1;
      Q.push(node);
    }//서
    if(y+1 < M && board[x][y+1] == 0){
      board[x][y+1] = day + 1;
      Node * node = (Node*)malloc(sizeof(Node));
      node->x = x;
      node->y = y+1;
      node->day = day+1;
      Q.push(node);
    }//동
  }
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      if(board[i][j] == 0){
        printf("-1");
        return 0;
      }
    }
  }
  printf("%d",max-1);
  return 0;
}
