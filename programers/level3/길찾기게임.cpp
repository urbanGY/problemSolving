#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }else {
        return a[1] > b[1];
    }
}
struct Node {
    int x;
    int y;
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

Node * root;
Node * cur;
Node * tmp;
vector<int> pre;
vector<int> post;

void findPre(Node * cur){
    if(cur == NULL) return;
    pre.push_back(cur->val);
    findPre(cur->left);
    findPre(cur->right);
}
void findPost(Node * cur){
    if(cur == NULL) return;
    findPost(cur->left);
    findPost(cur->right);
    post.push_back(cur->val);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int num = 1;
    for(auto & n : nodeinfo){
        n.push_back(num);
        num++;
    }
    sort(nodeinfo.begin(), nodeinfo.end() , cmp);
    cur = new Node();
    root = cur;
    cur->x = nodeinfo[0][0];
    cur->y = nodeinfo[0][1];
    cur->val = nodeinfo[0][2];
    for(int i = 1 ; i < nodeinfo.size() ; i++){
        int x = nodeinfo[i][0], y = nodeinfo[i][1], val = nodeinfo[i][2];
        cur = root;
        while(true){
            if(y < cur -> y && x < cur -> x){
                if(cur->left != NULL) cur = cur->left;
                else {
                    cur->left = new Node();
                    cur = cur->left;
                    cur->x = x;
                    cur->y = y;
                    cur->val = val;
                    break;
                }
            }else {
                if(cur->right != NULL) cur = cur->right;
                else {
                    cur->right = new Node();
                    cur = cur->right;
                    cur->x = x;
                    cur->y = y;
                    cur->val = val;
                    break;
                }
            }
        }
    }
    findPre(root);
    findPost(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
