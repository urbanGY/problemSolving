#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool cmp(string a, string b){
	if(a.size() == b.size()){
		return a < b;
	}else {
		return a.size() < b.size();
	}
}
int main() {
	int N;
	string s;
	vector<string> v;
	map<string, bool> m;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for(auto& val : v){
		if(!m[val]){
			cout<<val<<endl;
			m[val] = true;
		}

	}
	return 0;
}
