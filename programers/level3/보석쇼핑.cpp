#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <queue>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s;
    map<string,int> m;
    queue<string> q;
    int point = 1, term = 0, len = 0, start = 0, range = 987654321;
    for(auto gem : gems) s.insert(gem);
    len = s.size();

    for(auto gem : gems){
        m[gem] += 1;
        q.push(gem);
        if(m.size() == len){
            while(true){
                string tmp = q.front();
                if(m[tmp] > 1){
                    q.pop();
                    m[tmp] -= 1;
                    point += 1;
                }else {
                    term = q.size();
                    break;
                }
            }

            if(term < range){
                start = point;
                range = term;
            }
        }

    }

    answer.push_back(start);
    answer.push_back(start+range-1);
    return answer;
}
