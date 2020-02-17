#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    int left, right;
    if(s.size() == 1) return 1;
    if(s.size() == 2){
        if(s[0] == s[1]) return 2;
        else return 1;
    }
    for(int i = 0 ; i < s.size() ; i++){
        if((i == 0 || i+1 == s.size())) continue;
        left = i;
        right = i;
        while(s[left] == s[right] && left >= 0 && right < s.size()){
            left--;
            right++;
        }
        if(answer < (right-left-1)) answer = right-left-1;

        left = i;
        right = i+1;
        while(s[left] == s[right] && left >= 0 && right < s.size()){
            left--;
            right++;
        }
        if(answer < (right-left-1)) answer = right-left-1;
    }
    return answer;
}
