#include<iostream>
#include <vector>
using namespace std;
int minimum = 987654321;
int min_core = 987765321;
void show(vector<vector<int> > & board){
  int len = board.size();
  for(int i = 0 ; i < len ; i++){
    for(int j = 0 ; j < len ; j++){
      cout<<board[i][j]<<" ";
    }
    cout<<""<<endl;
  }
  cout<<""<<endl;
}
void find(vector<vector<int> > board, int x, int y, int core, int N, int cnt){
  // cout<<core<<" , "<<cnt<<endl;
  show(board);
  if(min_core > core){
    minimum = cnt;
  }else if(min_core == core){
    if(minimum > cnt) minimum = cnt;
  }

  for(int i = x ; i < N ; i++){
    for(int j = y ; j < N ; j++){
      if(board[i][j] == 1 && (i == 0 || j == 0 || i == N-1 || j == N-1)){
        board[i][j] = 2;
        core--;
      }else if(board[i][j] == 1){
        board[i][j] = 2;

        int tmp = j-1;
        bool flag = true;
        while(tmp >= 0){
          if(board[i][tmp] != 0) {
            flag = false;
            break;
          }
          board[i][tmp] = 2;
          tmp--;
        }
        if(flag) find(board, i, j, core-1, N, cnt+j);
        tmp++;
        while(tmp < j){
            board[i][tmp] = 0;
            tmp++;
        }

        tmp = i-1;
        flag = true;
        while(tmp >= 0){
          if(board[tmp][j] != 0){
            flag = false;
            break;
          }
          board[tmp][j] = 2;
          tmp--;
        }
        if(flag) find(board, i, j, core-1, N, cnt+i);
        tmp++;
        while(tmp < i){
          board[tmp][j] = 0;
          tmp++;
        }

        tmp = j+1;
        flag = true;
        while(tmp < N){
          if(board[i][tmp] != 0){
            flag = false;
            break;
          }
          board[i][tmp] = 2;
          tmp++;
        }
        if(flag) find(board, i, j, core-1, N, cnt+(N-j-1));
        tmp--;
        while(tmp > j){
          board[i][tmp] = 0;
          tmp--;
        }

        tmp = i+1;
        flag = true;
        while(tmp < N){
          if(board[tmp][j] != 0){
            flag = false;
            break;
          }
          board[tmp][j] = 2;
          tmp++;
        }
        if(flag) find(board, i, j, core-1, N, cnt+(N-i-1));
        tmp--;
        while(tmp > i){
          board[tmp][j] = 0;
          tmp--;
        }

      }

    }
  }
}


int main(int argc, char** argv)
{
  cout<<""<<endl;
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N, input, core = 0;
    vector<vector<int> > board;
    minimum = 987654321;
    min_core = 987654321;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
      vector<int> tmp;
      for(int j = 0 ; j < N ; j++){
        cin>>input;
        tmp.push_back(input);
        if(input == 1) core++;
      }
      board.push_back(tmp);
    }
    find(board, 0, 0, core, N, 0);
    cout<<"#"<<test_case<<" "<<minimum<<endl;
  }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
