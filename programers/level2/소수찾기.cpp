#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(char a, char b){
    return a > b;
}


bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2 ; i < n ; i++)
        if(n%i == 0) return false;
    return true;
}

bool check(vector<pair<int, bool> > input, int i){
    int tmp = i;
    while(i){
        int n = i%10;
        bool flag = true;
        for(auto& p : input){
            if(n == p.first && p.second == false){
                flag = false;
                p.second = true;
                break;
            }
        }
        if(flag) return false;
        i /= 10;
    }

    return isPrime(tmp);
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), cmp);
    int end = stoi(numbers);
    vector<pair<int, bool> > input;

    for(const auto& c : numbers){
        input.push_back(make_pair(c-'0',false));
    }

    for(int i = 2 ; i <= end ; i++){
        if(check(input,i)) answer++;
    }

    return answer;
}
