#include <string>
#include <vector>
#include <iostream>
using namespace std;
int gcd(int n, int m){
    int tmp = n%m;
    while(tmp != 0){
        n = m;
        m = tmp;
        tmp = n%m;
    }
    return m;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int val = gcd(n,m);
    answer.push_back(val);
    answer.push_back(n*m/val);
    return answer;
}
