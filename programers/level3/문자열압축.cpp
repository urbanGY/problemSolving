#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int find(string s, int n){
    // int len = strlen(s.c_str()), cnt = 0, i = n;
    int len = s.size(), cnt = 0, i = n;
    int answer = 0;
    string cur = s.substr(0,n);
    for(i = n ; i < len ; i += n){
        string tmp = s.substr(i,n);
        if(cur == tmp){
            if(i+n >= len){
                if(cnt < 9)
                    answer += 1+n;
                else if(cnt < 99)
                    answer += 2+n;
                else if(cnt < 999)
                    answer += 3+n;
                else
                    answer += 4+n;
                return answer;
            }
            else {
                cnt++;
            }
        } else {
            if(cnt == 0){
                answer += n;
            }else {
                if(cnt < 9)
                    answer += 1+n;
                else if(cnt < 99)
                    answer += 2+n;
                else if(cnt < 999)
                    answer += 3+n;
                else
                    answer += 4+n;
            }
            cnt = 0;
            cur = tmp;
        }
    }
    return answer+(len-(i-n));
}

int solution(string s) {
    // int answer = strlen(s.c_str());
    int answer = s.size();
    int max = answer/2;
    int n = 1;
    while(n <= max){
        int ans = find(s,n);
        if(answer > ans) answer = ans;
        n++;
    }
    return answer;
}
