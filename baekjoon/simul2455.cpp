#include <iostream>
using namespace std;

int main(){
  int max = 0;
  int current = 0;
  for(int i = 0 ; i < 4 ; i++){
    int out = 0;
    scanf("%d",&out);
    current -= out;

    int in = 0;
    scanf("%d", &in);
    current += in;
    if(max < current)
      max = current;
  }
  printf("%d",max);
  return 0;
}
