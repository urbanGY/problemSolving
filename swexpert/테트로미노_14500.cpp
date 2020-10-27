#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, answer = -1;
vector<vector<int> > board;
vector<vector<pair<int,int> > > pattern;
void setPattern() {
	pattern = vector<vector<pair<int,int> > >(19);
	pattern[0] = vector<pair<int,int> > {{0,0},{0,1},{1,0},{1,1}};

	pattern[1] = vector<pair<int,int> > {{0,0},{0,1},{0,2},{0,3}};
	pattern[2] = vector<pair<int,int> > {{0,0},{1,0},{2,0},{3,0}};

	pattern[3] = vector<pair<int,int> > {{0,0},{1,0},{2,0},{2,1}};
	pattern[4] = vector<pair<int,int> > {{0,0},{0,1},{0,2},{1,0}};
	pattern[5] = vector<pair<int,int> > {{0,0},{0,1},{1,1},{2,1}};
	pattern[6] = vector<pair<int,int> > {{0,0},{0,1},{0,2},{-1,2}};

	pattern[7] = vector<pair<int,int> > {{0,0},{1,0},{2,0},{2,-1}};
	pattern[8] = vector<pair<int,int> > {{0,0},{0,1},{0,2},{-1,0}};
	pattern[9] = vector<pair<int,int> > {{0,0},{0,1},{1,0},{2,0}};
	pattern[10] = vector<pair<int,int> > {{0,0},{0,1},{0,2},{1,2}};

	pattern[11] = vector<pair<int,int> > {{0,0},{1,0},{1,1},{2,1}};
	pattern[12] = vector<pair<int,int> > {{0,0},{0,1},{-1,1},{-1,2}};
	pattern[13] = vector<pair<int,int> > {{0,0},{1,0},{1,-1},{2,-1}};
	pattern[14] = vector<pair<int,int> > {{0,0},{0,1},{1,1},{1,2}};

	pattern[15] = vector<pair<int,int> > {{0,0},{0,1},{0,2},{-1,1}};
	pattern[16] = vector<pair<int,int> > {{0,0},{1,0},{2,0},{1,1}};
	pattern[17] = vector<pair<int,int> > {{0,0},{0,1},{0,2},{1,1}};
	pattern[18] = vector<pair<int,int> > {{0,0},{1,0},{2,0},{1,-1}};
}

bool isOkay(vector<pair<int,int> >& pat, int x, int y) {
	for(auto p : pat) {
		int nx = x + p.first, ny = y + p.second;
		if(nx < 0 || ny < 0 || nx >= N || ny >= M) return false;
	}
	return true;
}

int main() {
	scanf("%d %d",&N,&M);
	board = vector<vector<int> >(N,vector<int>(M,0));
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++) {
			scanf("%d",&board[i][j]);
		}
	}
	setPattern();
	for(auto pat : pattern) {
		for(int i = 0 ; i < N ; i++) {
			for(int j = 0 ; j < M ; j++) {
				if(isOkay(pat,i,j)) {
					int tmp = 0;
					for(auto pr : pat) {
						tmp += board[i+pr.first][j+pr.second];
					}
					if(tmp > answer) answer = tmp;
				}
			}
		}
	}
	printf("%d\n",answer);
	return 0;
}
