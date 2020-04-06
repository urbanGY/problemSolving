#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    map<int,bool> m;
    vector<int> answer;
    vector<vector<int>> v;
    for(int i = 1 ; i < s.size()-1 ; i++){
        char c = s.at(i);
        if(c == '{'){
            vector<int> tmp;
            string num = "";
            while(true){
                i++;
                char tmp_c = s.at(i);
                if(tmp_c == '}'){
                    tmp.push_back(stoi(num));
                    break;
                }else if(tmp_c >= '0' && tmp_c <= '9'){
                    num += tmp_c;
                }else if(tmp_c == ','){
                    tmp.push_back(stoi(num));
                    num = "";
                }
            }
            v.push_back(tmp);
        }else continue;
    }
    sort(v.begin(), v.end(), cmp);
    for(auto subset : v){
        for(auto elem : subset){
            if(m[elem] == false){
                m[elem] = true;
                answer.push_back(elem);
            }
        }
    }
    return answer;
}
