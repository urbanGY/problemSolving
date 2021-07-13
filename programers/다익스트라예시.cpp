#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

map<int,vector<int> > m;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int minVal(int a, int b) {
    return a < b ? a : b;
}

void dijikstra(int start, int n, vector<vector<pair<int,int> > >& board) {
    vector<int> distance(n+1,7654321);

    priority_queue<pair<int,int>, vector<pair<int, int> >, cmp> pq;
    pq.push(make_pair(start,0));
    distance[start] = 0;

    while(!pq.empty()){
        pair<int, int> pr = pq.top();
        pq.pop();
        int current = pr.first, cost = pr.second;
        if(cost > distance[current]) continue; // 이부분
        for(auto pr : board[current]) {
            int to = pr.first;
            if(cost+pr.second < distance[to]) { // 이부분중요
                distance[to] = cost+pr.second;
                pq.push(make_pair(to,distance[to]));
            }
        }
    }
    m[start] = distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<pair<int, int> > > board(n+1);
    for(auto fare : fares) {
        int from = fare[0], to = fare[1], cost = fare[2]; //이 문제는 같은경로인데 다른 값이 다시 들어오지 않음
        board[from].push_back(make_pair(to,cost));
        board[to].push_back(make_pair(from,cost));
    }
    for(int i = 1 ; i <= n ; i++) {
        dijikstra(i,n,board);
    }

    int together = 87654321;
    for(int i = 1 ; i <= n ; i++) {
        int tmp = m[s][i] + m[i][a] + m[i][b];
        // cout<<m[s][i]<<" , "<<m[i][a]<<" , "<<m[i][b]<<endl;
        if(together > tmp) together = tmp;
    }
    int other = m[s][a] + m[s][b];
    // cout<<together<<" , "<<other<<endl;
    return together < other ? together : other;
}
