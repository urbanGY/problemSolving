#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    int p = 0, y = 0;
    transform(s.begin(),s.end(),s.begin(),(int(*)(int))tolower);
    for(auto& c : s){
        if(c == 'p') p++;
        if(c == 'y') y++;
    }
    return p == y ? true : false;
}
