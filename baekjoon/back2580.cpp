#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > board(10,vector<int>(10,0));

void show(){
  for(int i = 1 ; i <= 9 ; i++){
    for(int j = 1 ; j <= 9 ; j++){
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }
}

int group(int x){
	int result;
	if(x <= 3){
		result = 1;
	}else if(x <= 6){
		result = 4;
	}else {
		result = 7;
	}
	return result;
}

void horizonal(int x, int y, vector<bool>& check){
	for(int i = 1 ; i <= 9 ; i++){
		check[board[x][i]] = true;
	}
}

void vertical(int x, int y, vector<bool>& check){
	for(int i = 1 ; i <= 9 ; i++){
		check[board[i][y]] = true;
	}
}

void cube(int x, int y, vector<bool>& check){
	int start_x = group(x), start_y = group(y);
	for(int i = start_x ; i < start_x+3 ; i++){
		for(int j = start_y ; j < start_y+3 ; j++){
			check[board[i][j]] = true;
		}
	}
}

void set(int x, int y){
  if(x == 10 && y == 1){
	show();
	exit(0); // 하나라도 답이면 끝!
  }
  if(board[x][y] == 0){
    vector<bool> check(10,false);
    horizonal(x,y,check);
    vertical(x,y,check);
    cube(x,y,check);
    for(int i = 1 ; i <= 9 ; i++)
      if(!check[i]){
        board[x][y] = i;
        if(y == 9) set(x+1,1);
        else set(x,y+1);
        board[x][y] = 0; //다시 이전 후보자로 돌아 갈 경우 되돌리는거
      }
  }else {
    if(y == 9) set(x+1,1);
    else set(x,y+1);
  }
}

int main() {
	for(int i = 1 ; i <= 9 ; i++){
		for(int j = 1 ; j <= 9 ; j++){
			scanf("%d",&board[i][j]);
		}
	}
	set(1,1);
	return 0;
}
