#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(string a, string b) { return a < b; }
string addTime(string start, int t){
    int hour = stoi(start.substr(0,2)), min = stoi(start.substr(3));
    min += t;
    if(min >= 60){
        hour += 1;
        min -= 60;
    }
    string result = "";
    if(hour < 10) result += ("0" + to_string(hour));
    else result += to_string(hour);
    result += ":";
    if(min < 10) result += ("0" + to_string(min));
    else result += to_string(min);
    return result;
}
string minTime(string start, int t){
    int hour = stoi(start.substr(0,2)), min = stoi(start.substr(3));
    min -= t;
    if(min < 0){
        hour -= 1;
        min += 60;
    }
    string result = "";
    if(hour < 10) result += ("0" + to_string(hour));
    else result += to_string(hour);
    result += ":";
    if(min < 10) result += ("0" + to_string(min));
    else result += to_string(min);
    return result;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    string busTime = "09:00", before;
    int index = 0, cur_timing = 0;
    sort(timetable.begin() , timetable.end() , cmp);
    for(int n_cnt = 0 ; n_cnt < n ; n_cnt++){
        cur_timing = 0;
        for(int i = index ; (i < timetable.size()) && (cur_timing < m) ; i++){
            if(timetable[i] <= busTime){
                index++;
                cur_timing++;
            }
        }
        before = busTime;
        busTime = addTime(busTime,t);
    }
    if(index == 0 || cur_timing < m){
        answer = before;
    }else {
        cout<<index<<endl;
        index -= 1;
        cout<<timetable[index]<<endl;
        answer = minTime(timetable[index],1);
    }

    return answer;
}
