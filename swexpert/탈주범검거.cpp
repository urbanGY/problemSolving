#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int n, m, sx, sy, term;
vector<vector<set<pair<int,int> > > > enable;
bool isOkay(int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        else return true;
}

bool canMove(int x, int y, int nx, int ny) {
        for(auto pr : enable[nx][ny] ) {
                if(pr.first == x && pr.second == y) return true;
        }
        return false;
}

vector<pair<int,int> > getNext(int x, int y, int type) {
        vector<pair<int,int> > pr;
        if(type == 1) {
                int x_[4] = {1,0,-1,0};
                int y_[4] = {0,1,0,-1};
                for(int i = 0; i < 4; i++)
                        if(isOkay(x+x_[i],y+y_[i]) && canMove(x,y,x+x_[i],y+y_[i])) pr.push_back({x+x_[i],y+y_[i]});
        }else if(type == 2) {
                int x_[2] = {1,-1};
                int y_[2] = {0,0};
                for(int i = 0; i < 2; i++)
                        if(isOkay(x+x_[i],y+y_[i]) && canMove(x,y,x+x_[i],y+y_[i])) pr.push_back({x+x_[i],y+y_[i]});
        }else if(type == 3) {
                int x_[2] = {0,0};
                int y_[2] = {1,-1};
                for(int i = 0; i < 2; i++)
                        if(isOkay(x+x_[i],y+y_[i]) && canMove(x,y,x+x_[i],y+y_[i])) pr.push_back({x+x_[i],y+y_[i]});
        }else if(type == 4) {
                int x_[2] = {-1,0};
                int y_[2] = {0,1};
                for(int i = 0; i < 2; i++)
                        if(isOkay(x+x_[i],y+y_[i]) && canMove(x,y,x+x_[i],y+y_[i])) pr.push_back({x+x_[i],y+y_[i]});
        }else if(type == 5) {
                int x_[2] = {1,0};
                int y_[2] = {0,1};
                for(int i = 0; i < 2; i++)
                        if(isOkay(x+x_[i],y+y_[i]) && canMove(x,y,x+x_[i],y+y_[i])) pr.push_back({x+x_[i],y+y_[i]});
        }else if(type == 6) {
                int x_[2] = {0,1};
                int y_[2] = {-1,0};
                for(int i = 0; i < 2; i++)
                        if(isOkay(x+x_[i],y+y_[i]) && canMove(x,y,x+x_[i],y+y_[i])) pr.push_back({x+x_[i],y+y_[i]});
        }else if(type == 7) {
                int x_[2] = {-1,0};
                int y_[2] = {0,-1};
                for(int i = 0; i < 2; i++)
                        if(isOkay(x+x_[i],y+y_[i]) && canMove(x,y,x+x_[i],y+y_[i])) pr.push_back({x+x_[i],y+y_[i]});
        }
        return pr;
}

void setEnable(int x, int y, int type, vector<vector<set<pair<int,int> > > >& enable) {
        if(type == 1) {
                int x_[4] = {1,0,-1,0};
                int y_[4] = {0,1,0,-1};
                for(int i = 0; i < 4; i++) {
                        int nx = x + x_[i], ny = y + y_[i];
                        if(isOkay(nx,ny)) enable[x][y].insert({nx,ny});
                }
        }else if(type == 2) {
                int x_[2] = {1,-1};
                int y_[2] = {0,0};
                for(int i = 0; i < 2; i++) {
                        int nx = x + x_[i], ny = y + y_[i];
                        if(isOkay(nx,ny)) enable[x][y].insert({nx,ny});
                }
        }else if(type == 3) {
                int x_[2] = {0,0};
                int y_[2] = {1,-1};
                for(int i = 0; i < 2; i++) {
                        int nx = x + x_[i], ny = y + y_[i];
                        if(isOkay(nx,ny)) enable[x][y].insert({nx,ny});
                }
        }else if(type == 4) {
                int x_[2] = {-1,0};
                int y_[2] = {0,1};
                for(int i = 0; i < 2; i++) {
                        int nx = x + x_[i], ny = y + y_[i];
                        if(isOkay(nx,ny)) enable[x][y].insert({nx,ny});
                }
        }else if(type == 5) {
                int x_[2] = {1,0};
                int y_[2] = {0,1};
                for(int i = 0; i < 2; i++) {
                        int nx = x + x_[i], ny = y + y_[i];
                        if(isOkay(nx,ny)) enable[x][y].insert({nx,ny});
                }
        }else if(type == 6) {
                int x_[2] = {0,1};
                int y_[2] = {-1,0};
                for(int i = 0; i < 2; i++) {
                        int nx = x + x_[i], ny = y + y_[i];
                        if(isOkay(nx,ny)) enable[x][y].insert({nx,ny});
                }
        }else if(type == 7) {
                int x_[2] = {-1,0};
                int y_[2] = {0,-1};
                for(int i = 0; i < 2; i++) {
                        int nx = x + x_[i], ny = y + y_[i];
                        if(isOkay(nx,ny)) enable[x][y].insert({nx,ny});
                }
        }
}

struct node {
        int x;
        int y;
        int time;
        vector<pair<int,int> > next;
        node(int x, int y, int time, vector<pair<int,int> > pr)
                : x(x), y(y), time(time), next(pr) {
        }
};


int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                int answer = 0;
                scanf(" %d %d %d %d %d",&n,&m,&sx,&sy,&term);
                enable = vector<vector<set<pair<int,int> > > >(n,vector<set<pair<int,int> > >(m)); // 불필요한 set의 활용 제거하기, map을 통해 값의 여부를 logn에 판단하게 하는게 좋을듯
                vector<vector<int> > board(n,vector<int>(m,0));
                vector<vector<bool> > check(n,vector<bool>(m,false));
                queue<node> q;
                for(int i = 0; i < n; i++)
                        for(int j = 0; j < m; j++) {
                                scanf(" %d",&board[i][j]);
                                setEnable(i,j,board[i][j],enable);
                        }

                q.push(node(sx,sy,1,getNext(sx,sy,board[sx][sy])));
                check[sx][sy] = true;
                while(!q.empty()) {
                        node cur = q.front();
                        q.pop();
                        int x = cur.x, y = cur.y, time = cur.time;
//            cout<<x<<" , "<<y<<endl;
                        answer++;
                        for(auto& pr : cur.next) {
                                int nx = pr.first, ny = pr.second;
                                if(isOkay(nx,ny) && !check[nx][ny] && time+1 <= term) {
                                        q.push(node(nx,ny,time+1,getNext(nx,ny,board[nx][ny])));
                                        check[nx][ny] = true;
                                }
                        }
                }
                printf("#%d %d\n",test_case,answer);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
