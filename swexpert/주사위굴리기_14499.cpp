#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int x, y;
int command;
vector<vector<int> > board;
vector<int> dice;
int head = 1, bottom = 6;
int t = 2, r = 3, b = 5, l = 4;

void move(int direct) {
	switch(direct) {
		case 1:
			y += 1;
			break;
		case 2:
			y -= 1;
			break;
		case 3:
			x -= 1;
			break;
		case 4:
			x += 1;
			break;
	}
}

void diceChange(int direct) {
	int _head = head, _bottom = bottom, _l = l, _r = r, _t = t, _b = b;
	if(direct == 1) { // 동쪽
		head = _l;
		bottom = _r;
		t = _t;
		b = _b;
		l = _bottom;
		r = _head;
	}
	if(direct == 2) { // 서쪽
		head = _r;
		bottom = _l;
		t = _t;
		b = _b;
		l = _head;
		r = _bottom;
	}
	if(direct == 3) { // 북쪽
		head = _b;
		bottom = _t;
		t = _head;
		b = _bottom;
		l = _l;
		r = _r;
	}
	if(direct == 4) { // 남쪽
		head = _t;
		bottom = _b;
		t = _bottom;
		b = _head;
		l = _l;
		r = _r;
	}
}

bool isOkay() {
	if(x < 0 || y < 0 || x >= N || y >= M) return false;
	return true;
}

int main() {
	scanf("%d %d",&N,&M);
	scanf("%d %d",&x,&y);
	scanf("%d",&command);
	board = vector<vector<int> >(N,vector<int>(M,0));
	dice = vector<int>(7);
	for(int i = 0 ; i < N ; i++) {
		for(int j = 0 ; j < M ; j++) {
			scanf("%d",&board[i][j]);
		}
	}
	for(int i = 0 ; i < command ; i++) {
		int direct;
		scanf("%d",&direct);
		int bx = x, by = y;
		move(direct);
		if(isOkay()) {
			diceChange(direct);
			if(board[x][y] == 0) { // 주사위 -> 바닥
				board[x][y] = dice[bottom];
			}else { // 바닥 -> 주사위, 바닥 -> 0
				dice[bottom] = board[x][y];
				board[x][y] = 0;
			}
			printf("%d\n",dice[head]);
		}else {
			x = bx;
			y = by;
		}
	}
	return 0;
}
