#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> pre;
vector<vector<int> > edge;
vector<int> buff;
vector<bool> visited;

void find(int node) {
    if(visited[node]) return;
    if(pre[node] != -1 && !visited[pre[node]]) {
        buff[pre[node]] = node; // buff는 나중에 실행되도록 저장해 두는 건데 미리 방문할 노드를 방문 할 경우 바로 이전 유보했던 이 노드를 방문하기 위해 현재 노드를 넣는다.
        return;
    }
    visited[node] = true;
    if(buff[node] != -1)
        find(buff[node]); // 여기의 반환값이 방문되었어야 할 노드가 되도록 위에서 node 값을 넣어두고 여기서 실행하게 한다.
    for(auto n : edge[node]) find(n);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    pre = vector<int>(n,-1);
    edge = vector<vector<int> >(n);
    buff = vector<int>(n,-1);
    visited = vector<bool>(n,false);
    for(auto& p : path) {
        edge[p[0]].push_back(p[1]);
        edge[p[1]].push_back(p[0]);
    }
    for(auto& o : order) {
        pre[o[1]] = o[0];
    }
    if(pre[0] != -1) return false;
    visited[0] = true;
    for(auto& node : edge[0]) find(node);
    for(int i = 0 ; i < n ; i++) if(!visited[i]) return false;
    return true;
}

// 트리 탐색 문제 같은데 o(1)로 풀 수 있다. visited를 통해서 방문 노드를 마킹하는 방법으로 한다.
