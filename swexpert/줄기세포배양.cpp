#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
int _x[4] = {-1,0,1,0};
int _y[4] = {0,1,0,-1};

int maxVal(int a, int b) {
        return a > b ? a : b;
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                int d_x = 500, d_y = 500;
                int N,M,K;
                scanf(" %d %d %d",&N,&M,&K);
                queue<pair<int,int> > qu;
                vector<vector<pair<int,int> > > board(1010,vector<pair<int,int> >(1010,{0,0}) );
                for(int i = 0; i <N; i++) {
                        for(int j = 0; j < M; j++) {
                                board[d_x+i][d_y+j].first = 0; // time
                                scanf(" %d",&board[d_x+i][d_y+j].second); // val
                                if(board[d_x+i][d_y+j].second != 0)
                                        qu.push({d_x+i,d_y+j});
                        }
                }
                for(int time = 1; time <= K; time++) {
                        int len = qu.size();
                        set<pair<int,int> > candidate;
                        for(int q = 0; q < len; q++) {
                                pair<int,int> pr = qu.front();
                                qu.pop();
                                int x = pr.first, y = pr.second;
                                int init = board[x][y].first, active = board[x][y].second;
                                if(init + active+1 == time) {
                                        for(int i = 0; i < 4; i++) {
                                                int nx = x + _x[i], ny = y + _y[i];
                                                if( (board[nx][ny].second == 0 || board[nx][ny].first == time) && board[nx][ny].second < active) {
                                                        board[nx][ny].first = time;
                                                        board[nx][ny].second = active;
                                                        candidate.insert({nx,ny});
                                                }
                                        }
                                }else {
                                        qu.push({x,y});
                                }
                        }
//            cout<<time<<" : "<<candidate.size()<<endl;
                        for(auto pr : candidate) {
                                qu.push({pr.first,pr.second});
                        }
                }
                int answer = 0;
                for(int i = 0; i < 1010; i++) {
                        for(int j = 0; j < 1010; j++) {
                                if(board[i][j].first + board[i][j].second + board[i][j].second > K) answer++;
                        }
                }
                printf("#%d %d\n",test_case,answer);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
