#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool> > v(n+1, vector<bool>(n+1,false));
    for(auto result : results) v[result[0]][result[1]] = true;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= n ; k++){
                if(v[j][i] && v[i][k]) v[j][k] = true;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        int count = 0;
        for(int j = 1 ; j <= n ; j++){
            if(v[i][j] || v[j][i]) count++;
        }
        if(count == n-1) answer++;
    }
    return answer;
}
