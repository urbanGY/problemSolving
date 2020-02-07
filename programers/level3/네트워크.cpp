#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
void find(vector<vector<int>>& computers, vector<int>& check, int start, int n, int x){
    for(int j = 0 ; j < n ; j++){
        if(computers[start][j] == 1 && check[j] == -1){
            check[j] = x;
            find(computers, check, j, n, x);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> check(n, -1);
    map<int, bool> m;

    for(int i = 0 ; i < n ; i++)
        find(computers, check, i, n, i);

    for(auto c : check)
        m[c] = true;

    return m.size();
}
