#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct node {
    bool sibling;
    node * next[26];
    map<int, int> m;
    node(){
        fill(next, next+26, nullptr);
        sibling = false;
    }
};

int find(node * pt, string& word, int index, int length){
    char c = word.at(index);
    if(c == '?'){
        return pt->m[length];
    }
    if(pt->next[c-'a'] != NULL) return find(pt->next[c-'a'], word, index+1, length);
    else return 0;
}

node * f_root;
node * r_root;
node * cur;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    f_root = new node;
    r_root = new node;

    for(auto & word : words){
        cur = f_root;
        int length = word.size();
        for(int i = 0 ; i < length ; i++){
            char c = word.at(i);
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new node;
                cur->sibling = true;
            }
            cur->m[length] += 1;
            cur = cur->next[c-'a'];
        }
        reverse(word.begin(), word.end());
        cur = r_root;
        for(int i = 0 ; i < length ; i++){
            char c = word.at(i);
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new node;
                cur->sibling = true;
            }
            cur->m[length] += 1;
            cur = cur->next[c-'a'];
        }
    }

    for(auto& query : queries){
        if(query.at(0) == '?'){
            cur = r_root;
            reverse(query.begin(),query.end());
        }
        else cur = f_root;
        int ans = find(cur, query, 0, query.size());
        answer.push_back(ans);
    }
    return answer;
}
