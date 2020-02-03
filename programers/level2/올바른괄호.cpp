#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int left = 0, right = 0;
    for(const auto& c : s){
        if(c == '(') left++;
        if(c == ')') right++;
        if(left < right) return false;
    }
    return left == right ? true : false;
}
