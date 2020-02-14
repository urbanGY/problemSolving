#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> input_list;
    bool flag = false;
    for(auto& oper : operations){
        char instruction = oper[0];
        if(instruction == 'I'){
            flag = true;
            int input = stoi(oper.substr(2));
            input_list.push_back(input);
        }else {
            if(flag){
                sort(input_list.begin(), input_list.end(), cmp);
                flag = false;
            }
            char operation = oper[2];
            if(operation == '-'){
                if(!input_list.empty())
                    input_list.pop_back();
            }else {
                if(!input_list.empty())
                    input_list.pop_front();
            }
        }
    }
    sort(input_list.begin(), input_list.end(), cmp);
    if(input_list.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else {
        int maximum = input_list.front();
        int minimum = input_list.back();
        answer.push_back(maximum);
        answer.push_back(minimum);
    }
    return answer;
}
