#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    map<string, int>::iterator i;
    for(auto& p : participant){
        m[p] += 1;
    }
    for(auto & p : completion){
        m[p] -= 1;
    }
    for(i = m.begin() ; i != m.end() ; i++){
        if(i->second != 0) answer = i->first;
    }
    return answer;
}
