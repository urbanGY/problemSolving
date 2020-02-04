#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> split(string s, int seq){
    vector<string> tmp;
    string head = "", number = "";
    int index = 0;
    for(int i = index ; i < s.size() ; i++){
        char c = s[i];
        if(!(c >= '0' && c <= '9')) head += c;
        else {
            index = i;
            break;
        }
    }
    transform(head.begin(), head.end(), head.begin(), (int(*)(int))toupper);
    for(int i = index ; i < s.size() ; i++ ){
        char c = s[i];
        if(c >= '0' && c <= '9') number += c;
        else {
            index = i;
            break;
        }
    }
    number = to_string(stoi(number));

    tmp.push_back(head);
    tmp.push_back(number);
    tmp.push_back(to_string(seq));
    tmp.push_back(s);
    return tmp;
}

bool cmp(vector<string> a, vector<string> b){
    if(a[0] == b[0]) {
        if(a[1] == b[1]){
            return stoi(a[2]) < stoi(b[2]);
        }else {
            return stoi(a[1]) < stoi(b[1]);
        }
    }else {
        return a[0] < b[0];
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> tmp;
    int index = 0;
    for(auto f : files){
        tmp.push_back(split(f, index));
        index++;
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for(auto split_str : tmp){
        answer.push_back(split_str[3]);
    }
    return answer;
}
