#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

struct Node {
    int x;
    int y;
    char direct;
    int cost;
    Node(int x, int y, char direct, int cost){
        this->x = x;
        this->y = y;
        this->direct = direct;
        this->cost = cost;
    }
};

struct cmp {
    bool operator()(Node * a, Node * b){
        return a->cost > b->cost;
    }
};

int next_x[4] = {0, 1, 0, -1};
int next_y[4] = {1, 0, -1, 0};

int solution(vector<vector<int>> board) {
    int answer = 0, N = board.size();
    priority_queue<Node *, vector<Node *>, cmp> pq;
    vector<vector<bool> > check(N, vector<bool>(N,false));
    pq.push(new Node(0,0,'n',0));
    while(!pq.empty()){
        Node * tmp = pq.top();
        pq.pop();   
        check[tmp->x][tmp->y] = true;
        if(tmp->x == N-1 && tmp->y == N-1){
            answer = tmp->cost;
            break;
        }
        for(int i = 0 ; i < 4 ; i++){
            int x = tmp->x + next_x[i];
            int y = tmp->y + next_y[i];
            if(x >= 0 && y >= 0 && x < N && y < N && !check[x][y] && board[x][y] == 0){
                char d = 'n';
                int cost = tmp->cost;
                if(!(x == tmp->x)) d = 'v';
                if(!(y == tmp->y)) d = 'h';
                if(tmp->direct == 'n'){    
                    cost += 100;
                }else if(d == tmp->direct){
                    cost += 100;
                }else {
                    cost += 600;
                }
                pq.push(new Node(x,y,d,cost));
            }
        }
    }
    return answer;
}