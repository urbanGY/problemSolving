#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int get_gcd(int a, int b){
    int tmp;
    while(b != 0){
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int get_lcm(int a, int b){
    return a*b/get_gcd(a,b);
}

int solution(vector<int> arr) {
    int lcm = arr[0];
    for(int i = 1 ; i < arr.size() ; i++){
        lcm = get_lcm(lcm,arr[i]);
    }
    return lcm;
}
