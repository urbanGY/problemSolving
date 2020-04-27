#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int * array = new int[9];
  int sum = 0;
  for(int i = 0 ; i < 9 ; i++){
    scanf("%d",&array[i]);
    sum += array[i];
  }
  sort(array,array+9);
  bool flag = false;
  for(int i = 0 ; i < 9 ; i++){
    for(int j = i+1 ; j < 9 ; j++){
      if(sum - (array[i] + array[j]) == 100){
        array[i] = -1;
        array[j] = -1;
        flag = true;
        break;
      }
    }
    if(flag) break;
  }
  for(int i = 0 ; i < 9 ; i++)
    if(array[i] != -1)
      printf("%d\n",array[i]);
  delete array;
  return 0;
}
