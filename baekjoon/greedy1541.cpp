#include <iostream>
#include <string>
using namespace std;

int main(){
  string input;
  cin>> input;
  int answer = 0;
  int tmp = 0;
  string num = "";
  bool flag = true;
  for(int i = 0 ; i < input.length() ; i++){
    if(input[i] == '+'){
      if(flag){
        answer += stoi(num);
      }else {
        answer -= stoi(num);
      }
      num = "";
    }else if(input[i] == '-'){
      if(flag){
        answer += stoi(num);
        flag = false;
      }else {
        answer -= stoi(num);
      }
      num = "";
    }else {
      num += input[i];
    }
  }
  printf("%d",flag?answer+stoi(num):answer-stoi(num));
  return 0;
}

//-가 나오기 전까지의 값들을 모두 괄호로 묶어서 더해 연산해버린다.
