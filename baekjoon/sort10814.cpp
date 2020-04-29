#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int main() {
	int N;
	string answer = "";
	scanf("%d",&N);
	vector<vector<string> > v(201,vector<string>());
	for(int i = 0 ; i < N ; i++){
		int age;
		string name;
		cin>>age>>name;
		v[age].push_back(name);
	}
	for(int i = 0 ; i < 201 ; i++){
		for(int j = 0 ; j < v[i].size() ; j++){
			answer += to_string(i)+ " " + v[i][j] + "\n";
		}
	}
	cout<<answer<<endl;
	return 0;
}
