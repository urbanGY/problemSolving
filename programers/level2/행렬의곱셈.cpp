#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int row = arr1.size();
    int col = arr2[0].size();
    int mid = arr2.size();
    for(int i = 0 ; i < row ; i++){
        vector<int> v;
        for(int j = 0 ; j < col ; j++){
            int tmp = 0;
           for(int x = 0 ; x < mid ; x++){
               tmp += (arr1[i][x] * arr2[x][j]);
           }
           v.push_back(tmp);
        }
        answer.push_back(v);
    }
    return answer;
}
