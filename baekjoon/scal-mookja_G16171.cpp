#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char * input = new char[101];
  char * temp = new char[101];
  char * keyWord = new char[101];
  scanf("%s",input);
  scanf("%s",keyWord);
  int input_index = 0;
  int temp_index = 0;
  while(input[input_index] != '\0'){
    if((input[input_index] >= 65 && input[input_index] <= 90) || (input[input_index] >= 97 && input[input_index] <= 122)){
      temp[temp_index] = input[input_index];
      temp_index++;
    }
    input_index++;
  }
  int keyWord_index = 0;
  while(keyWord[keyWord_index] != '\0'){
    keyWord_index++;
  }
  
  bool flag = false;
  for(int i = 0 ; i <= temp_index - keyWord_index ; i++){
    for(int j = 0 ; j <= keyWord_index ; j++){
      if(j == keyWord_index)
        flag = true;
      if(temp[i+j] != keyWord[j])
        break;
    }
    if(flag)
      break;
  }
  if(flag){
    printf("1");
  }else {
    printf("0");
  }
  return 0;
}
