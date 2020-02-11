#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> visit(101);

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int find(int node){
    if(node == visit[node]) return node;
    else {
        visit[node] = find(visit[node]);
        return visit[node];
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    for(int i = 0 ; i < n ; i++) visit[i] = i;
    for(auto& cost : costs){
        int start = find(cost[0]);
        int end = find(cost[1]);
        int val = cost[2];
        if(start != end){ // start , end 가 연결되지 않았다면
            visit[start] = end; // start의 부모가 end
            answer += val;
        }
    }
    return answer;
}
