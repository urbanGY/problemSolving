#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0, total = 1;
    map<string, int> m;
    pair<map<string, int>::iterator, bool> pr;
    for(auto clothe: clothes){
        string kindof = clothe[1];
        if(!m[kindof]){
            m[kindof] = 1;
        }else {
            m[kindof] += 1;
        }
    }

    for(map<string, int>::iterator i = m.begin() ; i != m.end() ; i++){
        total *= (i->second+1);
    }
    return total - 1;
}
