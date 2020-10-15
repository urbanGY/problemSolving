
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer;
int n, k;
int nextX[4] = {1,0,-1,0};
int nextY[4] = {0,1,0,-1};
void dfs(vector<vector<int> >& board, vector<vector<bool> >& check, int x, int y, bool flag, int length, int current) {
    if(current + length < answer-1) return;
    for(int i = 0 ; i < 4 ; i++) {
        int nx = x + nextX[i], ny = y+nextY[i];
        if(flag) {
            flag = !flag;
            for(int nk = k ; nk >= 1 ; nk--) {
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny] || board[nx][ny]-nk >= current ) continue;
			    check[nx][ny] = true;
	    		dfs(board,check,nx,ny,flag,length+1, board[nx][ny]-nk);
		    	check[nx][ny] = false;
            }
            flag = !flag;
        }
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny] || board[nx][ny] >= current ) continue;
	    check[nx][ny] = true;
	    dfs(board,check,nx,ny,flag,length+1,board[nx][ny]);
    	check[nx][ny] = false;
    }
    if(length > answer) {
        answer = length;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = -1;
        scanf(" %d %d",&n,&k);
        vector<vector<int> > board(n,vector<int>(n));
        vector<vector<pair<int,int> > > startLine(21);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                scanf(" %d",&board[i][j]);
                startLine[ board[i][j] ].push_back(make_pair(i,j));
            }
        }
        for(int i = 20 ; i >= 1 ; i--) {
			if(startLine[i].size() > 0) {
                for(auto pr : startLine[i]) {
					int x = pr.first, y = pr.second;
                    if(board[x][y] < answer-1) continue;
                    vector<vector<bool> > check(n,vector<bool>(n,false));
                    check[x][y] = true;
                    dfs(board,check,x,y,true,1,board[x][y]);
                }
                break;
            }
        }
        printf("#%d %d\n",test_case,answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
// 문제 조건에 가장 높은 봉우리에서 출발하는 것이라는 고정적인 조건이 있어서 그 부분만 탐색하면 되는데 모든 조건에 대해서 탐색해 시간안에 동작은 했지만 답이 틀렸다.
