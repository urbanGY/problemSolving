#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string> > active;
    map<string, string> name;


    for(int i = 0 ; i < record.size() ; i++){
        stringstream ss;
        string cmd, id, u_name;
        ss.str(record[i]);
        ss >> cmd;
        ss >> id;
        ss >> u_name;
        if(record[i][0] == 'E'){
            name[id] = u_name;
            active.push_back(make_pair(id,"님이 들어왔습니다."));
        }else if(record[i][0] == 'L'){
            active.push_back(make_pair(id,"님이 나갔습니다."));
        }else {
            name[id] = u_name;
        }
    }
    for(int i = 0 ; i < active.size() ; i++){
        string u_id = active[i].first, u_name;
        u_name = name[u_id];
        answer.push_back(u_name + active[i].second);
    }

    return answer;
}
