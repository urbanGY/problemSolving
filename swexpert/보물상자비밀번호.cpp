#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

void split(string s, set<string>& group) {
    int n = s.size();
    int part = n/4;
    for(int i = 0 ; i < 4 ; i++) {
        string tmp = s.substr(i*part,part);
        group.insert(tmp);
    }
}

bool cmp(string a, string b) {
    return a > b;
}

long long convert(string s) {
    int len = s.size();
    long long result = 0;
	for(int i = 0; i < len ; i++) {
        char c = s[i];
        result *= 16;
        if(c >= '0' && c <= '9') result += c - '0';
        else result += c-55;
    }
    return result;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        set<string> group;
		int n,k;
        string input;
        scanf(" %d %d",&n,&k);
		cin>>input;
        split(input,group);
		for(int i = 1 ; i < n/4 ; i++) {
            string tmp = input.substr(1,n-1);
            tmp += input[0];
            input = tmp;
			split(input,group);
        }
        vector<string> candidate;
        for(auto& str : group) {
            candidate.push_back(str);
        }
		sort(candidate.begin(),candidate.end(),cmp);
        printf("#%d %lld\n",test_case,convert(candidate[k-1]) );
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
