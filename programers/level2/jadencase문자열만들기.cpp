#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s[0] >= 'a' && s[0] <= 'z')
        answer += s[0]-32;
    else
        answer += s[0];
    for(int i = 1 ; i < s.size() ; i++){
        char c = s[i];
        if(s[i-1] == ' ' && (c >= 'a' && c <= 'z')){
            answer += c-32;
        }else if(s[i-1] != ' ' && (c >= 'A' && c <= 'Z')){
            answer += c+32;
        }else {
            answer += c;
        }
    }
    return answer;
}
