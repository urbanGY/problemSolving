#include <iostream>
using namespace std;

int main(){
  int T = 0;
  scanf("%d",&T);
  int fibonacci[43];
  fibonacci[0] = 1;
  fibonacci[1] = 0;
  fibonacci[2] = 1;
  for(int i = 3 ; i < 43 ; i++)
    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
  for(int i = 0 ; i < T ; i++){
    int input = 0;
    scanf("%d",&input);
    printf("%d %d\n",fibonacci[input],fibonacci[input+1]);
  }
  return 0;
}
