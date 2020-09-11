#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
    vector<Node *> next;
    map<int, int> m;
    Node() {
        next = vector<Node *>(26,NULL);
    }
};

Node * cur;
Node * front;
Node * tail;

int find(string& input, Node * current, int index, int length) {
    char c = input[index];
    if(c == '?') return current->m[length];
    if(current->next[c-'a'] != NULL) return find(input,current->next[c-'a'],index+1,length);
    else return 0;
}

void trieInit(Node* current, string word) {
    int length = word.size();
    for(auto& c: word) {
        if(current->next[c-'a'] == NULL) {
            current->next[c-'a'] = new Node;
        }
        current->m[length] += 1;
        current = current->next[c-'a'];
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    front = new Node;
    tail = new Node;

    for(auto word : words) {
        trieInit(front,word);
        reverse(word.begin(),word.end());
        trieInit(tail,word);
    }

    for(auto query : queries){
        int tmp;
        if(query[0] == '?'){
            reverse(query.begin(),query.end());
            cur = tail;
        }else {
            cur = front;
        }
        tmp = find(query,cur,0,query.size());
        answer.push_back(tmp);
    }

    return answer;
}
