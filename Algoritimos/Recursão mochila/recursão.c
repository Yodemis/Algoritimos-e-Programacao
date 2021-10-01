#include <stdio.h>
int subconjunto(int C[], int M, int N){
  int caso1,caso2;
  
  if(N==0){
    if(M==0)return 1;
    return 0;
  }

  caso1=subconjunto(C,M,N-1);
  caso2=subconjunto(C,M-C[N-1],N-1);
  return (caso1 || caso2);
}
int main(){

  int C[100],M,N;
  int i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&C[i]);
  }
  scanf("%d", &M);

  if(subconjunto(C,M,N)==1){
    printf("SIM\n");
  }else{
    printf("NAO\n");
  }
  return 0;
}
