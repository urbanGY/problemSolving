#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> dic;

vector<int> solution(string msg) {
    vector<int> answer;
    int len = msg.size();
    int max_len = 2, last_index = 26;
    for(int i = 0 ; i < 26 ; i++){
        string tmp = "";
        tmp += 'A'+i;
        dic[tmp] = i+1;
    }
    int i = 0;
    while(i < len){
        int tmp_len = 0, before_index = 0;
        while((i+tmp_len) < len){
            tmp_len++;
            string s = msg.substr(i,tmp_len);
            int cur_index = dic[s];
            // cout<<cur_index<<" , "<<s<<endl;
            if(cur_index){
                before_index = cur_index;
                if((i+tmp_len) == len){
                    answer.push_back(cur_index);
                    tmp_len++;
                }
            }else {
                answer.push_back(before_index);
                dic[s] = ++last_index;
                break;
            }
        }
        i += (tmp_len-1);
    }
    return answer;
}
