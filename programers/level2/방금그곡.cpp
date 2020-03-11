#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;
map<string, char> mm;

int getMin(string start, string end){
    int s_h = stoi(start.substr(0,2)), s_m = stoi(start.substr(3,2));
    int e_h = stoi(end.substr(0,2)), e_m = stoi(end.substr(3,2));
    e_m = e_m + (e_h-s_h)*60;
    return e_m - s_m;
}

string getM(string s){
    int len = s.size();
    string result = "";
    for(int i = 0 ; i < len ; i++){
        if(i+1 < len && s.at(i+1) == '#'){
            string tmp = s.substr(i,2);
            result += mm[tmp];
            i++;
        }else {
            string tmp = s.substr(i,1);
            result += mm[tmp];
        }
    }
    return result;
}

string refineM(int time, string s){
    int len = s.size();
    string result = "";
    int cnt = 0;
    for(int i = 0 ; i < time ; i++){
        if(cnt == len) cnt = 0;
        result += s.at(cnt);
        cnt++;
    }
    return result;
}

string solution(string m, vector<string> musicinfos) {
    char c = 'a';
    vector<string> input{"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    for(auto& s : input){
        mm[s] = c;
        c++;
    }
    string answer = "";
    string buf;
    string refine_m = getM(m);
    int conditionTime = 0, m_len = refine_m.size();
    for(auto& musicin : musicinfos){
        vector<string> v;
        stringstream ss(musicin);
        while(getline(ss,buf,',')){
            v.push_back(buf);
        }
        int time = getMin(v[0],v[1]);
        string refine_s = getM(v[3]);
        refine_s = refineM(time,refine_s);
        for(int i = 0 ; i <= (int)refine_s.size()-m_len ; i++){
            string tmp_s = refine_s.substr(i,m_len);
            if(tmp_s == refine_m){
                if(conditionTime < time){
                    answer = v[2];
                    conditionTime = time;
                }
            }
        }
    }
    if(answer.size() == 0) answer = "(None)";
    return answer;
}
