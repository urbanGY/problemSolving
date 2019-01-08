#include <iostream>
using namespace std;

int main(){
  int N;
  scanf("%d",&N);

  int array[12];
  array[1] = 1;
  array[2] = 2;
  array[3] = 4;
  for(int i = 4 ; i < 12 ; i++){
    array[i] = array[i - 1] + array[i - 2] + array[i - 3];
  }
  for(int i = 0 ; i < N ; i++){
    int input = 0;
    scanf("%d",&input);
    printf("%d\n",array[input]);
  }
  return 0;
}
