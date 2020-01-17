#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
bool cmp(pair<vector<int> ,int> a, pair<vector<int> ,int> b) {
    if(a.first[1] == b.first[1]){
        return a.first[0] < b.first[0];
    }else {
        return a.first[1] > b.first[1];
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<vector<int> , int> > tmp;
    int index = 1;
    for(auto& v : nodeinfo){
        tmp.push_back(make_pair(v, index++));
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for(auto& v : tmp){
        cout<<v.second<<endl;
    }
    return answer;
}
