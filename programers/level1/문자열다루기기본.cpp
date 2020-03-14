#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int len = s.size();
    if(!(len == 4 || len == 6)) return false;
    for(auto c : s){
        if(!(c >= '0' && c <= '9')) return false;
    }
    return true;
}
