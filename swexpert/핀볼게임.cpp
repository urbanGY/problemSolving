#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n;
int answer = 0, cnt;
vector<vector<int> > board;
map<pair<int,int>, pair<int,int> > holl;

bool isEdge(int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= n) return true;
        else return false;
}

int recover(int val) {
        if(val < 0) return 0;
        else if(val >= n) return n-1;
        else return val;
}

int back(int direct) {
        if(direct == 0) return 2;
        if(direct == 2) return 0;
        if(direct == 1) return 3;
        if(direct == 3) return 1;
}



int reflect(int direct, int type) {
        if(type == 1) {
                if(direct == 1 || direct == 0) return back(direct);
                if(direct == 2) return 1;
                if(direct == 3) return 0;
        }
        if(type == 2) {
                if(direct == 1 || direct == 2) return back(direct);
                if(direct == 0) return 1;
                if(direct == 3) return 2;
        }
        if(type == 3) {
                if(direct == 2 || direct == 3) return back(direct);
                if(direct == 0) return 3;
                if(direct == 1) return 2;
        }
        if(type == 4) {
                if(direct == 0 || direct == 3) return back(direct);
                if(direct == 2) return 3;
                if(direct == 1) return 0;
        }
        if(type == 5) return back(direct);
}

void find(int x, int y, int direct) {
        //cout<<"start : "<<x<<" , "<<y<<endl;
        int startX = x, startY = y;
        int x_[4] = {-1,0,1,0};
        int y_[4] = {0,1,0,-1};
        while(true) {
                int nx = x + x_[direct];
                int ny = y + y_[direct];
                //cout<<nx<<" ,"<<ny<<endl;
                if(isEdge(nx,ny)) {
                        //cout<<"edge"<<endl;
                        cnt++;
                        direct = back(direct);
                        x = nx; // 굳이 recover한 값으로 바꿔줄 필요가 없는게 direct를 수정해주고 순회 시 고려하는건 nx,ny이기 때문에 알아서 정상범주로 값이 돌아오게 된다.
                        y = ny;
                }else if(nx == startX && ny == startY) break;
                else if(board[nx][ny] == -1) break;
                else if(board[nx][ny] >= 6 && board[nx][ny] <= 10) {
                        x = holl[{nx,ny}].first;
                        y = holl[{nx,ny}].second;
                }else if(board[nx][ny] >= 1 && board[nx][ny] <= 5) {
                        cnt++;
                        direct = reflect(direct,board[nx][ny]);
                        x = nx;
                        y = ny;
                }else {
                        x = nx;
                        y = ny;
                }
        }
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                answer = 0;
                scanf(" %d",&n);
                board = vector<vector<int> >(n,vector<int>(n));
                map<int,vector<pair<int,int> > > m;
                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                                int input;
                                scanf(" %d",&input);
                                board[i][j] = input;
                                if(input >= 6 && input <= 10) {
                                        m[input].push_back({i,j});
                                        if(m[input].size() == 2) {
                                                holl[m[input][1]] = m[input][0];
                                                holl[m[input][0]] = m[input][1];
                                        }
                                }
                        }
                }
                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                                if(board[i][j] == 0) {
                                        for(int direct = 0; direct < 4; direct++) {
                                                cnt = 0;
                                                find(i,j,direct);
                                                if(cnt > answer) answer = cnt;
                                        }
                                }
                        }
                }
                printf("#%d %d\n",test_case,answer);
                holl.clear();
                m.clear();
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
