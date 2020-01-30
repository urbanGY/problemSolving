#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    vector<int> v;
    for(int i = 0 ; i <= n ; i++)
        v.push_back(i);
    while(true){
        int i = 1;
        int len = v.size();
        vector<int> tmp(1);
        while(i < len){
            int first = v[i], second = v[i+1];
            if((first == a && second == b) || (first == b && second == a)){
                return answer;
            }else if(first == a || first == b){
                tmp.push_back(first);
            }else if(second == a || second == b){
                tmp.push_back(second);
            }else {
                tmp.push_back(first);
            }
            i += 2;
        }
        v = tmp;
        answer++;
    }
    return answer;
}
