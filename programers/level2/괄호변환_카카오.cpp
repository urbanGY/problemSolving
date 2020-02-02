#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

bool is_right(string s){
    int left = 0, right = 0;
    for(const auto& c : s){
        if(right > left) return false;
        if(c == '(') left++;
        if(c == ')') right++;
    }
    return left == right?true:false;
}

pair<string, string> split(string p){
    int left = 0, right = 0;
    pair<string, string> pr = make_pair("","");
    for(int i = 0 ; i < p.size() ; i++){
        char c = p.at(i);
        if(c == '(') left++;
        if(c == ')') right++;
        if(left && right && left == right){
            string u = p.substr(0,i+1);
            string v = p.substr(i+1);
            pr.first = u;
            pr.second = v;
            break;
        }
    }
    return pr;
}

string find(pair<string, string> pr){
    string u = pr.first, v = pr.second;
    if(u.size() == 0 ) return "";
    if(is_right(u)){
        return u + find(split(v));
    }else {
        string temp_v = "("+find(split(v))+")";
        string temp_u = "";
        if(u.size() >= 4)
            u = u.substr(1,u.size()-2);
        else
            u = "";
        for(const auto& c : u){
            if(c == '(') temp_u += ')';
            if(c == ')') temp_u += '(';
        }
        return temp_v + temp_u;
    }
}

string solution(string p) {return find(split(p));}
