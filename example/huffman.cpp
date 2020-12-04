#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
	char c;
	int cnt;
	Node * left;
	Node * right;
	Node(char c, int cnt) 
	:c(c), cnt(cnt) {
		left = NULL;
		right = NULL;
	}
};

Node * root;

struct cmp {
	bool operator()(Node * a, Node * b) {
		return a->cnt > b->cnt;
	}
};

void traversal(Node * cur, string pick, map<char,string>& m) {
	//if(cur == NULL) return;
	//cout<<cur->c<<" , "<<pick<<endl;
	if(cur->left == NULL && cur->right == NULL) {
		m[cur->c] = pick;
		return;
	}
	traversal(cur->left, pick+"0", m);
	traversal(cur->right, pick+"1", m);
}

map<char, string> getCode(string input) {
	Node * cur;
	map<char,string> m;
	vector<int> cnt(256,0);
	priority_queue<Node *, vector<Node *>, cmp> pq;
	for(auto& c : input) {
		cnt[c]++;
	}
	for(int i = 0 ; i < 256 ; i++) {
		if(cnt[i] > 0) pq.push(new Node((char)i, cnt[i]));
	}
	
	while(!pq.empty()) {
		if(pq.size() == 1) {
			root = pq.top();
			pq.pop();
			break;
		}
		Node * a = pq.top();
		pq.pop();
		Node * b = pq.top();
		pq.pop();
		cur = new Node('_',a->cnt+b->cnt);
		cur->left = a;
		cur->right = b;
		pq.push(cur);
	}
	traversal(root,"",m);
	return m;
}

string hasing(string input) {
	string result = "";
	map<char,string> m = getCode(input);
	for(auto& c : input) {
		result += m[c];
	}
	return result;
}

string decode(string hashCode) {
	string result = "";
	Node * cur = root;
	for(auto& c : hashCode) {
		if(c == '0') {
			cur = cur->left;
		}
		if(c == '1') {
			cur = cur->right;
		}
		if(cur->left == NULL && cur->right == NULL) {
			result += cur->c;
			cur = root;
		}
	}
	return result;
}

int main() {
	string input;
	cin >> input;
	string hashCode = hasing(input);
	cout<<hashCode<<endl;
	string decodeCode = decode(hashCode);
	cout<<decodeCode<<endl;
	return 0;
}