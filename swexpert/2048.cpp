#include <iostream>
#include <vector>
using namespace std;
int N;
int answer = -1;

void turn(vector<vector<int> >& board, int direct) {
	if(direct == 0){ //top
		for(int i = 0 ; i < N ; i++) {
			vector<int> tmp;
			int before = -1;
			for(int j = 0 ; j < N ; j++) {
				if(board[j][i] == 0) continue;
				if(before == board[j][i]) {
					tmp.back() *= 2;
					before = -1;
				}else {
					tmp.push_back(board[j][i]);
					before = board[j][i];
				}
			}
			int size = tmp.size();
			for(int j = size ; j < N ; j++) tmp.push_back(0);
			for(int j = 0 ; j < N ; j++) {
				board[j][i] = tmp[j];
			}
		}
	}else if(direct == 1){ //right
		for(int i = 0 ; i < N ; i++) {
			vector<int> tmp;
			int before = -1;
			for(int j = N-1 ; j >= 0 ; j-- ) {
				if(board[i][j] == 0) continue;
				if(before == board[i][j]) {
					tmp.back() *= 2;
					before = -1;
				}else {
					tmp.push_back(board[i][j]);
					before = board[i][j];
				}
			}
			int size = tmp.size();
			for(int j = size ; j < N ; j++) tmp.push_back(0);
			for(int j = 0 ; j < N ; j++) {
				board[i][N-j-1] = tmp[j];
			}
		}
	}else if(direct == 2) { //bottom
		for(int i = 0 ; i < N ; i++) {
			vector<int> tmp;
			int before = -1;
			for(int j = N-1 ; j >= 0 ; j-- ) {
				if(board[j][i] == 0) continue;
				if(before == board[j][i]) {
					tmp.back() *= 2;
					before = -1;
				}else {
					tmp.push_back(board[j][i]);
					before = board[j][i];
				}
			}
			int size = tmp.size();
			for(int j = size ; j < N ; j++) tmp.push_back(0);
			for(int j = 0 ; j < N ; j++) {
				board[N-j-1][i] = tmp[j];
			}
		}
	}else { //left
		for(int i = 0 ; i < N ; i++) {
			vector<int> tmp;
			int before = -1;
			for(int j = 0 ; j < N ; j ++) {
				if(board[i][j] == 0) continue;
				if(before == board[i][j]) {
					tmp.back() *= 2;
					before = -1;
				}else {
					tmp.push_back(board[i][j]);
					before = board[i][j];
				}
			}
			int size = tmp.size();
			for(int j = size ; j < N ; j++) tmp.push_back(0);
			for(int j = 0 ; j < N ; j++) {
				board[i][j] = tmp[j];
			}
		}
	}
}

void find(vector<vector<int> > board, int cnt) {
	if(cnt == 5) {
		for(auto& line : board) {
			for(auto& elem : line) {
				if(elem > answer) answer = elem;
			}
		}
		return;
	}
	for(int i = 0 ; i < 4 ; i++) {
		vector<vector<int> > tmp = board;
		turn(tmp,i);
		// for(auto line : tmp) {
		// 	for(auto elem : line) {
		// 		cout<<elem<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		find(tmp,cnt+1);
	}
}
int main() {
	int input;
	scanf("%d",&N);
	vector<vector<int> > board(N,vector<int>(N));
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++) {
			scanf("%d",&board[i][j]);
		}
	}
	find(board,0);
	printf("%d\n",answer);
	return 0;
}
