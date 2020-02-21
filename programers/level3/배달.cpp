#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};



int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> distance(N+1,987654321);
    vector<bool> visited(N+1,false);
    vector<vector<int> > board(N+1,vector<int>(N+1,987654321));


    priority_queue<pair<int, int> , vector<pair<int, int> >, cmp > pq;

    for(const auto& input : road){
        int from = input[0], to = input[1], weight = input[2];
        if(board[from][to] != 987654321){
            if(board[from][to] > weight){
                board[from][to] = weight;
                board[to][from] = weight;
            }
        }else {
            board[from][to] = weight;
            board[to][from] = weight;
        }
    }

    pq.push(make_pair(1,0));
    distance[1] = 0;
    while(!pq.empty()){
        pair<int, int> pos = pq.top();
        int current = pos.first, weight = pos.second;
        pq.pop();
        if(visited[current]) continue; //굳이 밑의 for문에 갈 필요 없게!
        visited[current] = true;
        for(int i = 1 ; i <= N ; i++){
            if(board[current][i] != 987654321){
                distance[i] = min(distance[i], weight+board[current][i]);
                pq.push(make_pair(i,distance[i]));
            }
        }
    }
    for(int i = 1 ; i <= N ; i++){
        if(distance[i] <= K) answer++;
    }

    return answer;
}
