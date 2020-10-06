#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    int num = 1, i = -1 , j = 0;
    vector<int> answer;
    vector<vector<int> > tri(n,vector<int>(n,0));
    for(int t = 1 ; t <= n ; t++) {
        for(int l = 0 ; l <= n-t ; l++) {
            if(t%3 == 1) {
                i++;
            }else if(t%3 == 2) {
                j++;
            }else {
                i--;
                j--;
            }
            tri[i][j] = num;
            num++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++) {
            answer.push_back(tri[i][j]);
        }
    }
    return answer;
}
