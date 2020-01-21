#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(const auto& input : skill_trees){
        int check = -1;
        bool flag = true;
        for(int i = 0 ; i < input.size() ; i++){
            for(int j = 0 ; j < skill.size() ; j++){
                if(input[i] == skill[j]){
                    if(check+1 == j){
                        check = j;
                        continue;
                    }else{
                        flag = false;
                        answer++;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
    }
    return skill_trees.size() - answer;
}
