#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> val(n+1,-1);
    vector<vector<bool>> graph(n+1,vector<bool>(n+1,false));
    vector<bool> visited(n+1,false); //queue 반복에서 방문 여부 판단 위한 지표
    queue<pair<int,int> > q;
    for(auto& vertex : edge){
        graph[vertex[0]][vertex[1]] = true;
        graph[vertex[1]][vertex[0]] = true;
    }

    visited[1] = true;
    for(int i = 2 ; i <= n ; i++){
        if(graph[1][i]){
            q.push(make_pair(i,1));
            visited[i] = true;
            val[i] = 1;
        }
    }
    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; i++){
            if(graph[pos.first][i] && !visited[i]){
                visited[i] = true;
                val[i] = 1+pos.second;
                q.push(make_pair(i,val[i]));
            }
        }
    }
    sort(val.begin(), val.end(), cmp);
    for(int i = 0 ; i <= n ; i++){
        if(val[0] == val[i]) answer++;
    }
    return answer;
}
