#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, w, h;
int answer;
struct node {
        int x;
        int y;
        int val;
        node(int x, int y, int val)
                : x(x), y(y), val(val) {
        }
};

void find(int x_, int y_, int val_, vector<vector<int> >& board) {
        vector<vector<bool> > check(h,vector<bool>(w,false));
        queue<node> q;
        q.push(node(x_,y_,val_));
        check[x_][y_] = true;
        board[x_][y_] = 0;
        while(!q.empty()) {
                node cur = q.front();
                q.pop();
                int x = cur.x, y = cur.y, val = cur.val;
                for(int i = x-1; i > x-val; i--) { // top
                        if(i >= 0 && board[i][y] != 0 && !check[i][y]) {
                                if(board[i][y] > 1)
                                        q.push( node(i,y,board[i][y]) );
                                check[i][y] = true;
                                board[i][y] = 0;
                        }
                }
                for(int i = x+1; i < x+val; i++) { // bottom
                        if(i < h && board[i][y] != 0 && !check[i][y]) {
                                if(board[i][y] > 1)
                                        q.push( node(i,y,board[i][y]) );
                                check[i][y] = true;
                                board[i][y] = 0;
                        }
                }
                for(int i = y-1; i > y-val; i--) { // left
                        if(i >= 0 && board[x][i] != 0 && !check[x][i]) {
                                if(board[x][i] > 1)
                                        q.push( node(x,i,board[x][i]) );
                                check[x][i] = true;
                                board[x][i] = 0;
                        }
                }
                for(int i = y+1; i < y+val; i++) { // right
                        if(i < w && board[x][i] != 0 && !check[x][i]) {
                                if(board[x][i] > 1)
                                        q.push(node(x,i,board[x][i]));
                                check[x][i] = true;
                                board[x][i] = 0;
                        }
                }
        }
        int cnt = 0;
        for(int i = 0; i < w; i++) {
                vector<int> tmp;
                for(int j = 0; j < h; j++) {
                        if(board[j][i] != 0) {
                                tmp.push_back(board[j][i]);
                                board[j][i] = 0;
                        }
                }
                int size = tmp.size();
                cnt += size;
                for(int j = 0; j < size; j++) {
                        board[h-j-1][i] = tmp.back();
                        tmp.pop_back();
                }
        }
        if(cnt < answer) answer = cnt;
}
void position(int num, vector<vector<int> >& board) {
        if(num == n) {
                return;
        }
        for(int i = 0; i < w; i++) {
                int j = 0;
                vector<vector<int> > tmp = board;
                for(j; j < h; j++) {
                        if(tmp[j][i] != 0) {
                                find(j,i,tmp[j][i],tmp);
                                position(num+1,tmp);
                                break;
                        }
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
                answer = 987654321;
                scanf(" %d %d %d",&n,&w,&h);
                vector<vector<int> > board(h,vector<int>(w,0));
                for(int i = 0; i < h; i++) {
                        for(int j = 0; j < w; j++) {
                                scanf("%d",&board[i][j]);
                        }
                }
                position(0,board);
                printf("#%d %d\n",test_case,answer);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
