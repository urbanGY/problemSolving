#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int cur = 0;
    int day_point = 0;
    int supply_day = dates[day_point];
    priority_queue< int, vector<int>, less<int> > pq;
    while(cur < k){
        if(cur == supply_day){
            pq.push(supplies[day_point]);
            day_point++;
            if(day_point < dates.size())
                supply_day = dates[day_point];
        }
        if(stock == 0){
            stock += pq.top();
            pq.pop();
            answer++;
        }
        stock--;
        cur++;
    }
    return answer;
}
