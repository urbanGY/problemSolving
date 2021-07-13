#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

struct Node {
    int x;
    int y;
    int direct;
    int cost;
    Node(int x, int y, int direct, int cost)
    :x(x), y(y), direct(direct), cost(cost){

    }
};

struct cmp {
    bool operator()(Node * a, Node * b){
        return a->cost > b->cost;
    }
};

int ABS(int a) {
    return a > 0 ? a : -a;
}

int next_x[4] = {-1, 0, 1, 0};
int next_y[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    int answer = 987654321, N = board.size();
    priority_queue<Node *, vector<Node *>, cmp> pq;
    vector<vector<vector<int> > > val(N, vector<vector<int> >(N, vector<int>(4,987654321)));
    pq.push(new Node(0,0,0,0));
    pq.push(new Node(0,0,1,0));
    pq.push(new Node(0,0,2,0));
    pq.push(new Node(0,0,3,0));
    val[0][0][0] = 0;
    val[0][0][1] = 0;
    val[0][0][2] = 0;
    val[0][0][3] = 0;
    while(!pq.empty()){
        Node * tmp = pq.top();
        pq.pop();
        int cost = tmp->cost;
        int direct = tmp->direct;
        for(int i = 0 ; i < 4 ; i++){
            int x = tmp->x + next_x[i];
            int y = tmp->y + next_y[i];
            if(x >= 0 && y >= 0 && x < N && y < N && board[x][y] == 0){
                int extra = 100;
                if(ABS(direct - i) == 2) continue;
                if(!(direct == i)) extra += 500;
                if(cost+extra < val[x][y][i]){
                    val[x][y][i] = cost+extra;
                    pq.push(new Node(x,y,i,cost+extra));
                }
            }
        }
    }
    for(int i = 0 ; i < 4 ; i++) {
        if(val[N-1][N-1][i] < answer) answer = val[N-1][N-1][i];
    }
    return answer;
}

// 14번째 테스트 케이스 중 위가 정답, 아래가 원레 내가 짯던 코드의 결과
// 항상 가장 최소의 값 하나만을 갱신했기에 5300 이 나와야 하는 부분에서 5500이 나오게 되어 이 부분 하나 때문에 틀리게 된다.
/*
0   100        1500
100   700   800   900
    800  1400  1500  1600
1500   900  1500  1600  1700  1800
1600  1000  1600  1700        2400
1700  1100        1800              5100
2300        2500  1900        5600  5000  5600        6100
   3700  3100        4500  5100  4900  5300  5400  5500
3900  3800  3200  3800  3900        4800        6000  6100
   3900  3300  3900  4000  4100  4200  4300        6200

0   100        1500
100   700   800   900
    800  1400  1500  1600
1500   900  1500  1600  1700  1800
1600  1000  1600  1700        2400
1700  1100        1800              5100
2300        2500  1900        5600  5000  5600        6300
   3700  3100        4500  5100  4900  5500  5600  5700
3900  3800  3200  3800  3900        4800        6200  6300
   3900  3300  3900  4000  4100  4200  4300        6400
*/
