#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int get_size(vector<vector<int>>& board, int m, int n, int x, int y, int target){
    if((x >= m || x < 0) || (y >= n || y < 0) || (board[x][y] != target)) return 0;
    board[x][y] = -1;
    int top = get_size(board,m ,n ,x+1,y,target);
    int bottom = get_size(board,m ,n ,x-1,y,target);
    int left = get_size(board,m ,n ,x,y-1,target);
    int right = get_size(board,m ,n ,x,y+1,target);
    return 1+top+bottom+left+right;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(picture[i][j] == 0 || picture[i][j] == -1)
                continue;
            else {
                number_of_area++;
                int target = picture[i][j];
                int cnt = get_size(picture,m ,n , i, j, target);
                if(cnt > max_size_of_one_area) max_size_of_one_area = cnt;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}
