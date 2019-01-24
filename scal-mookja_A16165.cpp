#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <queue>
using namespace std;
struct cmp {
  bool operator()(char * a, char * b){
    if(strcmp(a, b) > 0){ //a가 더 크면 == 아스키코드상 뒤 == 사전 정렬상 뒤로 가는게 참
      return true;
    }else {
      return false;
    }
  }
};
int main(){
  priority_queue<char *,vector<char *>,cmp > heap;
  int N = 0, question = 0;
  scanf("%d %d",&N, &question);
  char *** input;
  input = new char ** [N+1];
  int * groupLength = new int [N+1];
  char * group = new char [100];
  int memberNum = 0;
  for(int i = 0 ; i < N ; i++){
    scanf("%s",group);
    scanf("%d",&memberNum);
    groupLength[i] = memberNum;
    input[i] = new char * [memberNum+1];
    input[i][0] = new char [100];
    strcpy(input[i][0],group);
    for(int j = 1 ; j <= memberNum ; j++){
        input[i][j] = new char [100];
        scanf("%s",input[i][j]);
        heap.push(input[i][j]);
    }
    for(int j = 1 ; j <= memberNum ; j++){
      input[i][j] = heap.top();//strcpy(input[i][j], heap.top())으로 하면 안됨
      heap.pop();
    }
  }

  char * q = new char [100];
  int type = -1;
  for(int i = 0 ; i < question ; i++){
    scanf("%s",q);
    scanf("%d",&type);
    if(type == 1){//1 return group name
      for(int n = 0 ; n < N ; n++){
        for(int g = 1 ; g <= groupLength[n] ; g++){
          if(strcmp(q,input[n][g]) == 0){
            printf("%s\n",input[n][0]);
            break;
          }
        }
      }
    }else {//0 return member
      for(int n = 0 ; n < N ; n++){
        if(strcmp(q,input[n][0]) == 0){
          for(int g = 1 ; g <= groupLength[n] ; g++){
            printf("%s\n",input[n][g]);
          }
          break;
        }
      }
    }
  }

  delete[] q;
  delete[] group;
  delete[] groupLength;
  delete[] input;
  //if(음수가 들어가도 참으로 반환, 오직 0만 거짓)
  return 0;
}
