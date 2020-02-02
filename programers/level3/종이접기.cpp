#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    int N = pow(2,n);
    int len = N-1;
    int sum = 2;
    vector<int> answer(len);
    int tmp = N;
    while(sum <= N){
        bool flag = false;
        int start = (int)(len/tmp);
        for(int i = start ; i < len ; i += sum){
            if(flag){
                answer[i] = 1;
                flag = false;
            }
            else flag = true;
        }
        tmp /= 2;
        sum *= 2;
    }
    return answer;
}
