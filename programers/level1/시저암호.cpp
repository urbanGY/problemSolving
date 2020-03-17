#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(auto& c : s){
        int tmp = c;
        tmp += n;
        if(c >= 'a' && c <= 'z'){
            if(tmp > 122) tmp -= 26;
            answer += (char)tmp;
        }else if(c >= 'A' && c <= 'Z'){
            if(tmp > 90) tmp -= 26;
            answer += (char)tmp;
        }else
            answer += c;
    }
    return answer;
}
