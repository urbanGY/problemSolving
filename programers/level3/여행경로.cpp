#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;
vector<vector<string> > candidate;
bool cmp(vector<string> a, vector<string> b){
    int len = a.size();
    for(int i = 0 ; i < len ; i++){
        if(a[i] == b[i]) continue;
        else {
            return a[i] < b[i];
        }
    }
}
void find(string start, vector<vector<string> >& tickets, vector<bool> check, vector<string> pick){
    if(pick.size() == tickets.size()+1){
        candidate.push_back(pick);
        return;
    }
    for(int i = 0 ; i < tickets.size() ; i++){
        vector<string> ticket = tickets[i];
        if(start == ticket[0] && check[i] == false){
            check[i] = true;
            pick.push_back(ticket[1]);
            find(ticket[1], tickets, check, pick);
            pick.pop_back();
            check[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int n = tickets.size();
    vector<bool> check(n+1, false);
    vector<string> pick;
    pick.push_back("ICN");
    find("ICN",tickets,check,pick);
    sort(candidate.begin(), candidate.end(), cmp);
    answer = candidate[0];
    return answer;
}
