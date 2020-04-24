#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int getTerm(string term){
    int result = 0;
    float f = stof(term);
    result = (int)(f*1000);
    return result;
}

pair<int, int> setTime(string endTime, string term){
    int hour = stoi(endTime.substr(0,2)) * 60 * 60 * 1000;
    int min = stoi(endTime.substr(3,5)) * 60 * 1000;
    int sec = stoi(endTime.substr(6,8)) * 1000;
    int msec = stoi(endTime.substr(9));
    int end = (hour + min + sec + msec);
    int termSec = getTerm(term);
    int start = (end - termSec + 1) < 0 ? 0 : (end - termSec + 1);
    return make_pair(start, end);
}

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int solution(vector<string> lines) {
    int answer = 0;
    string day, time, sec;
    vector<pair<int,int>> v;
    for(auto & line : lines){
        stringstream ss(line);
        ss >> day;
        if(day != "2016-09-15") continue;
        ss >> time;
        ss >> sec;
        v.push_back(setTime(time,sec));
    }

    for(auto point : v){
        int cnt = 0, start_p = point.first, end_p = start_p+999;
        for(auto val : v){
            if(!(end_p < val.first || start_p > val.second)) {
                cnt++;
            }
        }
        if(cnt > answer) answer = cnt;

        cnt = 0 , start_p = point.second , end_p = start_p + 999;
        for(auto val : v){
            if(!(end_p < val.first || start_p > val.second)) {
                cnt++;
            }
        }
        if(cnt > answer) answer = cnt;
    }

    return answer;
}
