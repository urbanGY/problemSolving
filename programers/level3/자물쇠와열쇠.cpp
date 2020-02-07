#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> board){
    int len = board.size();
    vector<vector<int>> v;
    for(int i = 0 ; i < len ; i++){
        vector<int> tmp(len);
        v.push_back(tmp);
    }

    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len ; j++){
            v[len-1-j][i] = board[i][j];
        }
    }
    return v;
}

void show(vector<vector<int>>& v){
    for(auto r : v){
        for(auto c : r){
            cout<<c<<" ";
        }
        cout<<""<<endl;
    }
    cout<<""<<endl;
}

bool set(vector<vector<int>>& key, vector<vector<int>>& lock, int x, int y){
    int key_len = key.size() , lock_len = lock.size();
    int n = lock_len + (key_len-1)*2;

    vector<vector<int>> board;
    for(int i = 0 ; i < n ; i++){
        vector<int> tmp(n);
        board.push_back(tmp);
    }

    int start = key_len-1;
    for(int i = 0 ; i < lock_len ; i++){
        for(int j = 0 ; j < lock_len ; j++){
            board[i+start][j+start] += lock[i][j];
        }
    }
    for(int i = 0 ; i < key_len ; i++){
        for(int j = 0 ; j < key_len ; j++){
            board[i+x][j+y] += key[i][j];
        }
    }

    for(int i = 0 ; i < lock_len ; i++){
        for(int j = 0 ; j < lock_len ; j++){
            if(board[i+start][j+start] != 1) return false;
        }
    }
    return true;
}

bool find(vector<vector<int>>& key, vector<vector<int>>& lock){
    int key_len = key.size() , lock_len = lock.size();
    int end = lock_len + key_len - 1;
    for(int i = 0 ; i < end ; i++){
        for(int j = 0 ; j < end ; j++){
            if(set(key,lock,i,j)) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for(int i = 0 ; i < 4 ; i++){
        if(find(key, lock)) return true;
        key = rotate(key);
    }
    return false;
}
