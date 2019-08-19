#include <iostream>
using namespace std;

unsigned long long int com[31][31];

int main(){
  for(int n = 1 ; n < 30 ; n++){
    com[n][1] = n;
    com[n][n] = 1;
  }

  for(int n = 3 ; n < 30 ; n++){
    for(int r = 2 ; r < n ; r++){
      com[n][r] = com[n-1][r-1] + com[n-1][r];
    }
  }

  int N;
  scanf("%d",&N);
  for(int i = 0 ; i < N ; i++){
    int a, b;
    scanf("%d %d",&a,&b);
    printf("%llu\n",com[b][a]);
  }
  return 0;
}
