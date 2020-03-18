#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a, char b){
    return a < b;
}
long long solution(long long n) {
    long long answer = 0;
    string s = "";
    while(n > 0){
        int c = n%10;
        s += (char)c+'0';
        n/=10;

    }
    sort(s.begin(), s.end(), cmp);

    int i = 1;
    for(auto& c : s){
        answer += (int)(c-'0')*i;
        i *= 10;
    }
    return answer;
}
