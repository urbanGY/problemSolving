#include <iostream>
using namespace std;

int main(){
  int count = 0;
  int purpose = 0;
  scanf("%d",&purpose);
  while(purpose != 1){
    if(purpose%2 == 1)
      count++;
    purpose /= 2;
  }
  printf("%d",++count);
  return 0;
}
