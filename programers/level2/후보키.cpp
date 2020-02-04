#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

vector<string> set_list;
bool cmp(string a, string b){
    return a.size() < b.size();
}
bool is_unique(vector<vector<string>>& relation, string set){
    if(set.empty()) return false;
    map<string, bool> m;
    pair<map<string, bool>::iterator, bool> pr;
    for(const auto& s : relation){
        string tmp = "";
        for(int i = 0 ; i < set.size() ; i++){
            tmp += s[set.at(i)-'0'];
        }
        pr = m.insert(pair<string, bool>(tmp,true));
        if(pr.second == false){
            return false;
        }
    }
    return true;
}

void find(vector<vector<string>>& relation, int col_size, int start, string pick){
    // if(start != 0)
    //     set_list.push_back(pick);
    if(is_unique(relation, pick)){
        set_list.push_back(pick);
        return;
    }
    for(int i = start ; i < col_size ; i++ ){
        find(relation, col_size, i+1, pick+to_string(i));
    }

}

int solution(vector<vector<string>> relation) {
    int col_size = relation[0].size();
    vector<string> answer;

    find(relation, col_size, 0, "");
    sort(set_list.begin(), set_list.end(), cmp);
    for(auto s : set_list){
        if(answer.empty()){
            answer.push_back(s);
        }
        else {
            bool flag = true;
            for(auto a : answer){
                int cnt = 0;
                for(auto c : a){
                    for(int i = 0 ; i < s.size() ; i++){
                        if(c == s[i]){
                            cnt++;
                            break;
                        }
                    }
                }
                if(cnt == a.size()){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                answer.push_back(s);
            }
        }
    }
    return answer.size();
}
// 012
// 02
