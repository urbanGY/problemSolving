#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
bool cmp(vector<int> a, vector<int> b) {
    if(a[0] == b[0]){
        return a[1] < b[1];
    }else{
         return a[0] < b[0];
    }
}

struct cmp_min {
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), cmp);
    int answer = 0, ms = 0, task = 0;
    priority_queue<vector<int>, vector<vector<int> >, cmp_min> pq;
    vector<vector<int>> ans;
    vector<int> pos;

    pos = jobs[task];
    ms = pos[0];
    pos.push_back(jobs[task][1]);
    task++;

    while(ans.size() < jobs.size()){
        while(task < jobs.size() && ms == jobs[task][0]){
            pq.push(jobs[task]);
            task++;
        }
        if(pos[2] <= 0){
            if(pos[2] == 0){
                pos.push_back(ms);
                ans.push_back(pos);
            }
            if(!pq.empty()){
                pos = pq.top();
                pq.pop();
                int tmp = pos[1];
                pos.push_back(tmp);
            }
        }

        pos[2] -= 1;
        ms++;
    }
    for(auto a : ans){
        answer += (a[3] - a[0]);
    }

    return answer/jobs.size();
}
