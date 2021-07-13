#include <iostream>
#include <vector>
using namespace std;
int N, M;
int wallCnt = 0;
int answer = 987654321;
vector<vector<int> > board;
int _x[4] = {-1,0,1,0};
int _y[4] = {0,1,0,-1};
int find(int x, int y, vector<vector<bool> >& check) {
	int count = 0;
	for(int d = 0 ; d < 4 ; d++) {
		int nx = x+_x[d], ny = y+_y[d];
		if(nx < 0 || ny < 0 || nx >= N || ny >= M || check[nx][ny] || board[nx][ny] != 0) continue;
		check[nx][ny] = true; // 시간 절약을 위해 탐색이 가능한 지점이면 일단 마킹하고 탐색에 뛰어든다.
		count += find(nx,ny,check);
	}
	return count + 1;
}

void block(int x, int y, int cnt) {
	if(cnt == 3) {
		vector<vector<bool> > check(N,vector<bool>(M,false));
		int tmp = 0;
		for(int i = 0 ; i < N ; i++) {
			for(int j = 0 ; j < M ; j++) {
				if(board[i][j] == 2 && !check[i][j]) {
					check[i][j] = true;
					tmp += find(i,j,check); // 굳이 board에 값을 변화시키지 않더라도 check에서 방문여부를 결정하면 같은 효과를 낼 수 있다.
				}
			}
		}
		if(tmp < answer) {
			answer = tmp;
			// cout<<tmp<<endl;
			// for(auto line : board) {
			// 	for(auto elem : line) {
			// 		cout<<elem<<" ";
			// 	}
			// 	cout<<endl;
			// }
			// cout<<endl;
		}
		return;
	}
	bool flag = true; // 2차원 배열의 순회를 매개변수의 시작부분으로부터 하는데 이 부분의 맹점은 y에 대해서 개행이 이뤄질 경우 다음 행의 0이 아니라 매개변수로부터 시작한다는 것이다.
	int start; // 이를 해결하기위해 flag로 개행여부 발생을 판단하고 개행이 발생하면 ,flag가 false가 된다면 y의 순회 시작점을 0으로 바꿔서 하는 것으로 한다.
	for(int i = x ; i < N ; i++) { // 칸막이 3개를 2차원 배열을 순회하며 모두 배열해야 하는데 이 부분이 복잡하다.
		if(flag) start = y;
		else start = 0; // 개행이 발생해서 0부터 시작
		for(int j = start ; j < M ; j++) {
			if(board[i][j] == 0) {
				board[i][j] = 1;
				if(j+1 == M) {
					block(i+1,0,cnt+1);
					flag = false;
				}else block(i,j+1,cnt+1);
				board[i][j] = 0;
			}
		}
		flag = false; // board의 값이 0이고 개행이 발생하면 위에서 처리해주지만 만약 0이 아닌 다른 값인데 개행이 발생한 상황이라면 이 부분으로 제어가 올 것이고 여기에 flag를 설정하면 마찬가지로 잘 동작하게 된다.
	}
}
int main() {
	scanf("%d %d",&N,&M);
	board = vector<vector<int> >(N,vector<int>(M,0));
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++) {
			scanf("%d",&board[i][j]);
			if(board[i][j] == 1) wallCnt++;
		}
	}
	block(0,0,0);
	printf("%d\n",N*M - answer - wallCnt - 3);
	return 0;
}
