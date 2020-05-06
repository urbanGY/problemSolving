#include <iostream>
#include <string>
using namespace std;
long long N, cnt = 0, answer;
bool check(int n){
	string s = to_string(n);
	for(int i = 0 ; i <= s.size()-3 ; i++){
		if(s.substr(i,3) == "666") return true;
	}
	return false;
}

int main() {
	cin >> N;
	long long i = 666;
	while(cnt != N){
		if(check(i)){
			cnt++;
			answer = i;
		}
		i++;
	}
	cout<<answer<<endl;
	return 0;
}
