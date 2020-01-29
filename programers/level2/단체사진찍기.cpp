#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

vector<bool> check(8);
vector<char> pick(8);
string candidate;
int cnt;

void find(int index, vector<string>& data){
    if(index == 8){
        for(auto& s : data){
            char a = s[0], b = s[2], op = s[3], condition = s[4]-'0';
            int a_index, b_index, distance;
            for(int i = 0 ; i < 8 ; i++){
                if(pick[i] == a)
                    a_index = i;
                if(pick[i] == b)
                    b_index = i;
            }
            distance = abs(a_index-b_index) - 1;

            if(op == '>'){
                if(distance <= condition)
                    return;
            }else if(op == '<'){
                if(distance >= condition)
                    return;
            }else {
                if(distance != condition)
                    return;
            }
        }
        cnt++;
        return;
    }

    for(int i = 0 ; i < 8 ; i++){
        if(!check[i]){
            check[i] = true;
            pick[index] = candidate[i];
            find(index+1, data);
            check[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    cnt = 0;
    candidate = "ACFJMNRT";
    find(0, data);
    return cnt;
}
