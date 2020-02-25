#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int solution(string word, vector<string> pages) {
    transform(word.begin(), word.end(), word.begin(), (int(*)(int))tolower);
    int answer = 0;
    int index = 0;
    map<string,pair<int, double> > m;
    vector<string> input_list;
    vector<pair<vector<int>, vector<string> > > infos;
    for(auto& page : pages){
        transform(page.begin(), page.end(), page.begin(), (int(*)(int))tolower);
        vector<int> v_index;
        vector<string> v_str;
        string::size_type b = 0;
        int foreign = 0, cnt = 0;
        string tmp = "";
        b = page.find(" content=\"https://");
        for(int i = b+10 ; i < 1501 ; i++){
            if(page.at(i) == '"') break;
            tmp += page.at(i);
        }
        v_str.push_back(tmp);
        input_list.push_back(tmp);
        b = 0;
        while(true) {
            b = page.find("<a href=\"https://",b+1);
            if(string::npos != b){
                foreign++;
                tmp = "";
                for(int i = b+9 ; i < 1501 ; i++){
                    if(page.at(i) == '"') break;
                    tmp += page.at(i);
                }
                v_str.push_back(tmp);
            }else break;
        }
        b = 0;
        while(true){
            b = page.find(word,b+word.size());
            if(string::npos == b) break;
            else {
                char front = page.at(b-1), back = page.at(b+word.size());
                if((front >= 'a' && front <= 'z')||(back >= 'a' && back <= 'z')) continue;
                else cnt++;
            }
        }
        v_index.push_back(index);
        v_index.push_back(cnt);
        v_index.push_back(foreign);
        m[v_str[0]] = make_pair(index,(double)cnt);
        infos.push_back(make_pair(v_index,v_str));
        index++;
    }
    for(auto& info : infos){
        vector<int> tmp_index = info.first;
        vector<string> tmp_str = info.second;
        for(int i = 1 ; i < tmp_str.size() ; i++){
            m[tmp_str[i]].second += ((double)tmp_index[1]/(double)tmp_index[2]);
        }
    }
    pair<int, double> max = make_pair(987654321,0.0);
    pair<int, double> pr;
    for(auto& input : input_list){
        pr = m[input];
        int seq = pr.first;
        double value = pr.second;
        if(max.second == value){
            if(max.first > seq){
                max.first = seq;
                max.second = value;
            }
        }else if(max.second < value){
            max.first = seq;
            max.second = value;
        }
    }
    return max.first;
}
