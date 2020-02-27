#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b){ //first 고유번호, second 재생횟수.
        if(a.second == b.second){
            return a.first > b.first;
        }else {
            return a.second < b.second;
        }
    }
};
bool v_cmp(pair<int,priority_queue<pair<int, int>, vector<pair<int, int> > , cmp> > a, pair<int,priority_queue<pair<int, int>, vector<pair<int, int> > , cmp> > b){
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, pair<int,priority_queue<pair<int, int>, vector<pair<int, int> > , cmp> > >m;
    map<string, pair<int,priority_queue<pair<int, int>, vector<pair<int, int> > , cmp> > >::iterator itor;
    vector<pair<int,priority_queue<pair<int, int>, vector<pair<int, int> > , cmp> > > v;
    for(int i = 0 ; i < genres.size() ; i++){
        if(m[genres[i]].first == 0){
            m[genres[i]].second = priority_queue<pair<int, int>, vector<pair<int, int> > , cmp>();
        }
        m[genres[i]].second.push(make_pair(i,plays[i]));
        m[genres[i]].first += plays[i];
    }
    for(itor = m.begin() ; itor != m.end() ; itor++){
        v.push_back(itor->second);
    }
    sort(v.begin(), v.end(), v_cmp);
    for(auto & el : v){
        int cnt = 0;
        while(!el.second.empty() && cnt < 2){
            cnt++;
            int tmp = el.second.top().first;
            answer.push_back(tmp);
            el.second.pop();
        }
    }
    return answer;
}
