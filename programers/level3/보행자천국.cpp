#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<int> > vertical(m+1,vector<int>(n+1,0));
    vector<vector<int> > horizonal(m+1,vector<int>(n+1,0));
    vertical[1][1] = 1;
    horizonal[1][1] = 1;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if((i == 0 && j == 0) || city_map[i][j] == 1) continue;
            else if(city_map[i][j] == 2){
                vertical[i+1][j+1] = vertical[i][j+1];
                horizonal[i+1][j+1] = horizonal[i+1][j];
            }else {
                vertical[i+1][j+1] = (vertical[i][j+1] + horizonal[i+1][j])%MOD;
                horizonal[i+1][j+1] = (vertical[i][j+1] + horizonal[i+1][j])%MOD;
            }
        }
    }
    answer = vertical[m][n];
    return answer;
}
