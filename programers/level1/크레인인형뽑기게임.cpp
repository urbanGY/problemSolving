#include <string>
#include <vector>

using namespace std;
vector<int> stack;
int count;
void pick(vector<vector<int>>& board, int col){
    int len = board.size();
    for(int i = 0 ; i < len ; i++){
        if(board[i][col] != 0){
            int choice = board[i][col];
            board[i][col] = 0;
            if(!stack.empty()){
                int tmp = stack.back();
                if(tmp == choice){
                    stack.pop_back();
                    count += 2;
                    return;
                }
            }
            stack.push_back(choice);
            return;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    count = 0;
    for(auto move : moves){
        pick(board,move-1);
    }
    return count;
}
