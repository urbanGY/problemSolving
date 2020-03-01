#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
map<string, char> m;

int get_min(string start, string end){
    int start_hour = stoi(start.substr(0,2)), end_hour = stoi(end.substr(0,2));
    int start_min = stoi(start.substr(3,2)), end_min = stoi(end.substr(3,2));
    if(start_hour > end_hour) end_hour = 24;
    return (end_min-start_min) + (end_hour-start_hour)*60;
}
string change_str(string s){
    s += " ";
    string tmp = "";
    for(int i = 0 ; i < s.size()-1 ; i++){
        char a = s.at(i), b = s.at(i+1);
        string st = "";
        if(b == '#'){
            st += a;
            st += b;
            tmp += m[st];
            i++;
        }else {
            st += a;
            tmp += m[st];
        }
    }
    return tmp;
}
string solution(string my, vector<string> musicinfos) {
    string val[] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    for(char i = 0 ; i < 12 ; i++){
        m[val[i]] = 'a'+i;
    }
    my = change_str(my);
    // cout<<my<<endl;
    pair<string, int> answer = make_pair("(None)",0);
    for(auto s : musicinfos){
        vector<string> tmp;
        stringstream ss(s);
        string buf = "", refine = "";
        while(getline(ss,buf,',')){
            tmp.push_back(buf);
        }
        int min = get_min(tmp[0], tmp[1]);
        int c = 0, index = 0;
        while(index < min){
            char b_c = buf.at(c);
            c++;
            refine += b_c;
            if(c == buf.size()) c = 0;
            if(b_c != '#') index++;
        }
        refine = change_str(refine);
        // cout<<"refine : "<<refine<<endl;
        int len = refine.size() - my.size();
        for(int i = 0 ; i <= len ; i++){
            string sub = refine.substr(i,my.size());
            if(my == sub){
                if(answer.second < min){
                    answer.first = tmp[2];
                    answer.second = min;
                    break;
                }
            }
        }
    }
    return answer.first;
}
