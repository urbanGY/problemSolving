#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int N;
vector<vector<bool>> board(16,vector<bool>(16,false));
bool check(int x, int y){
	int i, j;
	//vertical
	for(i = 0 ; i < x ; i++)
		if(board[i][y]) return false;
	i = x;
	j = y;
	for(;(i >= 0) && (j >= 0);i--,j--){
		if(board[i][j]) return false;
	}

	i = x;
	j = y;
	for(;(i >= 0) && (j < N);i--,j++){
		if(board[i][j]) return false;
	}
	return true;
}

void find(int x){
	if(x == N) {
		cnt++;
		return;
	}

	for(int i = 0 ; i < N ; i++){
		if(check(x,i)){
			board[x][i] = true;
			find(x+1);
			board[x][i] = false;
		}
	}

}

int main() {
	scanf("%d",&N);
	find(0);
	printf("%d",cnt);
	return 0;
}
