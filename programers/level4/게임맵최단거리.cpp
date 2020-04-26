#include<vector>
#include<iostream>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
    int val;
    Node(int x, int y, int val){
        this->x = x;
        this->y = y;
        this->val = val;
    }
};

int solution(vector<vector<int> > maps)
{
	int answer = 0, n = maps.size(), m = maps[0].size();
    vector<vector<bool> > board(n,vector<bool>(m,false));
    queue<Node> q;
    board[0][0] = true;
    q.push(Node(0,0,0));
    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        int x = tmp.x , y = tmp.y, val = tmp.val + 1;
        if(x == n-1 && y == m-1){
            answer = val;
            break;
        }
        if(x-1 >= 0 && !board[x-1][y] && maps[x-1][y] == 1){
            board[x-1][y] = true;
            q.push(Node(x-1,y,val));
        }
        if(x+1 < n && !board[x+1][y] && maps[x+1][y] == 1){
            board[x+1][y] = true;
            q.push(Node(x+1,y,val));
        }
        if(y-1 >= 0 && !board[x][y-1] && maps[x][y-1] == 1){
            board[x][y-1] = true;
            q.push(Node(x,y-1,val));
        }
        if(y+1 < m && !board[x][y+1] && maps[x][y+1] == 1){
            board[x][y+1] = true;
            q.push(Node(x,y+1,val));
        }
    }
	return answer == 0 ? -1 : answer;
}
