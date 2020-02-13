#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
bool is_fine(string a, string b){
    int len = a.size();
    int cnt = 0;
    for(int i = 0 ; i < len ; i++)
        if(a.at(i) == b.at(i)) cnt++;

    if(len-1 == cnt) return true;
    else return false;
}
int count(vector<bool>& v){
    int cnt = 0;
    for(const auto& a : v){
        if(a == true) cnt++;
    }
    return cnt;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int minimum = 987654321;
    int len = words.size();
    queue<pair<string, vector<bool> > > q;
    for(int i = 0 ; i < len ; i++){
        if(is_fine(begin, words[i])){
            vector<bool> tmp(len,false);
            tmp[i] = true;
            q.push(make_pair(words[i],tmp));
        }
    }
    while(!q.empty()){
        pair<string, vector<bool> > pos = q.front();
        q.pop();
        if(pos.first == target){
            int cnt = count(pos.second);
            if(minimum > cnt) minimum = cnt;
        }
        for(int i = 0 ; i < len ; i++){
            if(!(pos.second[i]) && is_fine(pos.first,words[i])){
                pos.second[i] = true;
                q.push(make_pair(words[i],pos.second));
                pos.second[i] = false; // 여기가 중요! 값이 누적되기 때문에 다시 바꿔줘야한다 ㅎㅎ
            }
        }
    }
    answer = minimum == 987654321? 0 : minimum;
    return answer;
}
