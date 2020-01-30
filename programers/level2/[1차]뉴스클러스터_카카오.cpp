#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

string refine(string str){
    string result = "";
    for(auto c : str){
        if(c >= 'a' && c <= 'z'){
            result += c;
        }else if(c >= 'A' && c <= 'Z'){
            result += (c+32);
        }else {
            result += ' ';
        }
    }
    return result;
}

vector<pair<string, bool> > make_set(string str){
    str = refine(str);
    vector<pair<string, bool> > v;
    for(int i = 0 ; i < str.size()-1 ; i++){
        string tmp = str.substr(i,2);
        if(tmp.front() == ' ' || tmp.back() == ' '){
            continue;
        }else {
            v.push_back(make_pair(tmp,true));
        }
    }
    return v;
}

float jacard(vector<pair<string, bool> > v1, vector<pair<string, bool> > v2){
    int intersection = 0, sum = v1.size() + v2.size();
    pair<string, bool> pos;
    for(auto& pr1 : v1){
        for(auto& pr2 : v2){
            if((pr1.first == pr2.first) && pr2.second){
                pr2.second = false;
                intersection++;
                break;
            }
        }
    }
    sum -= intersection;
    if(sum == 0) return 1.0;
    return (float)intersection/(float)sum;
}

int solution(string str1, string str2) {
    vector<pair<string, bool> > v1 = make_set(str1);
    vector<pair<string, bool> > v2 = make_set(str2);
    float j = jacard(v1, v2);
    return (int)(j*65536);
}
