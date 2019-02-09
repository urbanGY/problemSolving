#include <iostream>
#include <utility>
#include <queue>
using namespace std;

//BFS
int board[100][100];
bool check[100][100];
int main(){
  int N = 0;
  scanf("%d",&N);

  for(int i = 0 ; i < N ; i++){
    for(int n = 0 ; n < N ; n++){
      scanf("%d",&board[i][n]);
      check[i][n] = false;
    }
  }
  //판 생성
  pair<int, int> pos;
  queue< pair<int,int> > Q; // > > 띄어쓰기
  Q.push(make_pair(0,0));
  while(!Q.empty()){
    pos = Q.front();
    Q.pop();
    int move = board[pos.first][pos.second];
    int x = pos.first;
    int y = pos.second;

    if(move == -1) break;//목적지 도착햇음으로 loop 정지
    if((y + move < N)&&(check[x][y + move] == false)){//뒤에 처음 방문하는지 체크하는 제한이 없으면 메모리 초과라고 뜸
      check[x][y + move] = true;
      Q.push(make_pair(x,y + move));
    }
    if((x + move < N)&&(check[x + move][y] == false)){
      check[x + move][y] = true;
      Q.push(make_pair(x + move,y));
    }
  }
  if(check[N-1][N-1]){
    printf("HaruHaru");
  }else {
    printf("Hing");
  }
  return 0;
}
