#include <string>
#include <vector>
#include <iostream>
using namespace std;
void decToBin(vector<vector<bool> >& v , vector<int> arr){
    int vector_index = 0;
    for(auto& val : arr){
        int index = v.size() - 1;
        while(val > 0){
            int mod = val%2;
            if(mod == 1){
                v[vector_index][index] = true;
                index--;
            }else {
                v[vector_index][index] = false;
                index--;
            }
            val /= 2;
        }
        vector_index++;
    }
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<bool> > board1(n,vector<bool>(n,false));
    vector<vector<bool> > board2(n,vector<bool>(n,false));
    decToBin(board1,arr1);
    decToBin(board2,arr2);
    for(int i = 0 ; i < n ; i++){
        string tmp = "";
        for(int j = 0 ; j < n ; j++){
            if(board1[i][j] == true || board2[i][j] == true){
                tmp += "#";
            }else {
                tmp += " ";
            }
        }
        answer.push_back(tmp);
    }
    return answer;
}
