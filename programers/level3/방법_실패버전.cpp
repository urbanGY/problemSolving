#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<bool> check(22,false);
vector<int> result;
bool flag = false;
long long goal;
long long cnt = 0;
void find(vector<int> pick, int n){
    if(flag) return;
    if(pick.size() == n){
        cnt++;
        if(cnt == goal){
            for(const auto& p : pick)
                result.push_back(p);
            flag = true;
        }
        return;
    }
    for(int i = 1;  i <= n ; i++){
        if(!check[i]){
            check[i] = true;
            pick.push_back(i);
            find(pick,n);
            pick.pop_back();
            check[i] = false;
        }
    }
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<long long> factorial(22,1);
    for(long long i = 2 ; i < 21 ; i++)
        factorial[i] = factorial[i-1]*i;
    long long tmp;
    long long index;
    long long N = n;


    while(true){
        index = 1;
        N -= 1;
        tmp = factorial[N];
        if(tmp >= k){
            goal = k;
            break;
        }
        while((tmp*index) < k){
            index++;
        }

        k -= tmp*(index-1);
        for(int i = 1 ; i <= n ; i++){
            if(!check[i]){
                index--;
                if(index == 0){
                    check[i] = true;
                    answer.push_back(i);
                    break;
                }
            }
        }
    }
    find(answer,n);
    // answer = result;
    return result;
}
