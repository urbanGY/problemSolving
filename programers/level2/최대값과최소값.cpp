#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a < b;
}
string solution(string s) {
    string answer = "";
    string buf;
    stringstream ss(s);
    vector<int> v;
    while(ss >> buf){
        v.push_back(stoi(buf));
    }
    sort(v.begin(), v.end(), cmp);
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size()-1]);
    return answer;
}
