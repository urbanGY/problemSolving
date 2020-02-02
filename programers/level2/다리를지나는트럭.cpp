#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1, b_point = 0, cur = 0, t_point = 1;
    vector<pair<int, int> > v;
    v.push_back(make_pair(truck_weights[0],bridge_length));
    cur += truck_weights[0];
    while(b_point < truck_weights.size()){
        for(int i = b_point ; i < v.size() ; i++){
            v[i].second -= 1;
            if(v[i].second == 0){
                cur -= v[i].first;
                b_point++;
            }
        }
        if(cur + truck_weights[t_point] <= weight){
            v.push_back(make_pair(truck_weights[t_point],bridge_length));
            cur += truck_weights[t_point];
            t_point++;
        }
        time++;
    }
    return time;
}
