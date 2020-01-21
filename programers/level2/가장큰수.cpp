#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(const auto& elem : numbers){
        v.push_back(to_string(elem));
    }
    sort(v.begin(), v.end(), cmp);
    for(const auto& c : v)
        answer += c;
    if(answer[0] == '0') answer = "0";
    return answer;
}
