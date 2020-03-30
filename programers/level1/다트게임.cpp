#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0, index = 0;
    vector<int> inputList;
    for(int i = 0 ; i < dartResult.size() ; i++){
        char c = dartResult.at(i);
        int num;
        if(c >= '0' && c <= '9'){
            if(c == '1' && i+1 < dartResult.size() && dartResult.at(i+1) == '0'){
                num = 10;
                i++;
            }else {
                num = c - '0';
            }
            // cout<<"input num : "<<num;
            i++;
        }
        if(i < dartResult.size()){
            c = dartResult.at(i);

            if(c == 'S') {
                inputList.push_back(num);
            }else if(c == 'D'){
                num = num * num;
                inputList.push_back(num);
            }else if(c == 'T'){
                num = num * num * num;
                inputList.push_back(num);
            }else if(c == '*'){
                int tmp1 = inputList.back();
                inputList.pop_back();
                tmp1 *= 2;
                if(!inputList.empty()) {
                    int tmp = inputList.back();
                    inputList.pop_back();
                    tmp *= 2;
                    inputList.push_back(tmp);
                }
                inputList.push_back(tmp1);
            }else if(c == '#'){
                int tmp1 = inputList.back();
                inputList.pop_back();
                tmp1 *= -1;
                // if(!inputList.empty()) {
                //     int tmp = inputList.back();
                //     inputList.pop_back();
                //     tmp *= -1;
                //     inputList.push_back(tmp);
                // }
                inputList.push_back(tmp1);
            }
        }
    }
    for(auto num : inputList){
        answer += num;
    }
    return answer;
}
