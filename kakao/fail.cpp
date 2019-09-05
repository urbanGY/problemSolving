#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else {
        return a.second > b.second;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> tmp(N+2, 0);
    vector<pair<int, double> > result;
    int stage_len = stages.size();
    for(int i = 0 ; i < stage_len ; i++)
        tmp[stages[i]] += 1;

    int trial = stage_len, stop = 0, stage = 1;
    for(int i = 1 ; i <= N ; i++){
        stop = tmp[i];
        if(stop == 0){
            result.push_back(make_pair(i,0.0));
        }else {
            result.push_back(make_pair(i,(double)stop/trial));
        }
        trial -= stop;
    }

    sort(result.begin(),result.end(),cmp);
    for(int i = 0 ; i < result.size() ; i++){
        answer.push_back(result[i].first);
    }
    return answer;

}
// 1 2 2 2  3 3 4 6
//     0/1 0
//     1/2 0.5
//     1/2 0.5
//     3/7 0.42
//     1/8 0.125
