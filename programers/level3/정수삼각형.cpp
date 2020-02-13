#include <string>
#include <vector>
#include <iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    if(triangle.size() == 1){
        return triangle[0][0];
    }else {
        int len = triangle.size()-1;
        int raw = 1;
        for(int i = 1 ; i < triangle.size() ; i++){
            triangle[i][0] += triangle[i-1][0];
            // cout<<triangle[i][0]<<" ";
            for(int j = 1 ; j < raw ; j++){
                triangle[i][j] += max(triangle[i-1][j-1],triangle[i-1][j]);
                // cout<<triangle[i][j]<<" ";
            }
            raw++;
            triangle[i][i] += triangle[i-1][i-1];
            // cout<<triangle[i][i]<<endl;
        }
        for(const auto& line : triangle[len]){
            if(line > answer) answer = line;
        }
    }
    return answer;
}
