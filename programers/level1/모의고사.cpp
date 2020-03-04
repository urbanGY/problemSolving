#include <string>
#include <vector>
#include <iostream>

using namespace std;
int getMax(int a, int b, int c){
    return a < (b < c ? c : b) ? (b < c ? c : b) : a;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one{1,2,3,4,5};
    vector<int> two{2,1,2,3,2,4,2,5};
    vector<int> three{3,3,1,1,2,2,4,4,5,5};
    int i_1 = 0, i_2 = 0, i_3 = 0;
    int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0;
    for(auto& answer : answers){
        if(i_1 == 5) i_1 = 0;
        if(i_2 == 8) i_2 = 0;
        if(i_3 == 10) i_3 = 0;
        if(one[i_1] == answer) cnt_1++;
        if(two[i_2] == answer) cnt_2++;
        if(three[i_3] == answer) cnt_3++;
        i_1++;
        i_2++;
        i_3++;
    }
    int max_val = getMax(cnt_1,cnt_2,cnt_3);
    if(max_val == cnt_1) answer.push_back(1);
    if(max_val == cnt_2) answer.push_back(2);
    if(max_val == cnt_3) answer.push_back(3);
    return answer;
}
