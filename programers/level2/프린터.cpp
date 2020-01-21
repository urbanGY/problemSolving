#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int point_print = 0, point_pri = 0;
    vector<pair<int, int> > print_list;
    for(int i = 0 ; i < priorities.size() ; i++){
        if(i == location){
            print_list.push_back(make_pair(priorities[i],1));
        }else {
            print_list.push_back(make_pair(priorities[i],0));
        }
    }
    sort(priorities.begin(), priorities.end(), cmp);

    while(true){
        int cur = print_list[point_print].first;
        int cur_location = print_list[point_print].second;
        if(cur_location == 1 && cur == priorities[point_pri]){
            answer++;
            break;
        }else if(cur == priorities[point_pri]){
            point_pri++;
            point_print++;
            answer++;
        }else {
            print_list.push_back(make_pair(cur,cur_location));
            point_print++;
        }
    }
    return answer;
}
