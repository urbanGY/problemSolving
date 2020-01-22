#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(string a, string b){
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, bool> m;
    vector<int> len;
    sort(phone_book.begin(), phone_book.end(), cmp);
    for(auto& elem: phone_book){
        if(len.empty()){
            m[elem] = true;
            len.push_back(elem.size());
            continue;
        }
        for(auto& length : len){
            string prefix = elem.substr(0,length);
            if(m.find(prefix) != m.end()){
                answer = false;
                break;
            }

        }
        if(!answer) break;
        m[elem] = true;
        len.push_back(elem.size());
    }

    return answer;
}
