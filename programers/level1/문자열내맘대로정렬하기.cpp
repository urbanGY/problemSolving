#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int N = 0;
bool cmp(string a, string b){
    if(a.at(N) == b.at(N)) return a < b;
    else return a.at(N) < b.at(N);
}
vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(),strings.end(),cmp);
    return strings;
}
