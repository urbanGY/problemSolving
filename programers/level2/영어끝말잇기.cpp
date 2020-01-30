#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    char before = words[0][0];
    vector<int> answer(2,1);
    map<string, int> m;
    pair<map<string, int>::iterator, bool> pr;
    for(auto& word : words){
        pr = m.insert(pair<string, int>(word,1));
        if(pr.second == true && before == word.at(0)){
            answer[0] += 1;
            if(answer[0] > n){
                answer[1] += 1;
                answer[0] %= n;
            }
            before = word.back();
        }else {
            return answer;
        }
    }
    answer[0] = 0;
    answer[1] = 0;
    return answer;
}
