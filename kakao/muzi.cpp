#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int solution(vector<int> food_times, long long k) {
    long long stage = 0, index = 1;
    vector<pair<int, int> > v;
    for(auto& it : food_times){
        v.push_back(make_pair(it, index++));
    }
    sort(v.begin(), v.end());
    int size = v.size();
    int before = 0;
    for(auto it = v.begin() ; it != v.end() ; it++, size--){
        long long eat = (long long)(it->first - before) * size;
        if(eat == 0) continue;

        if(eat <= k){
            k -= eat;
            before = it->first;
        }else {
            k %= size;
            sort(it, v.end(), cmp);
            return (it + k) ->second;
        }
    }
    return -1;
}
