#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int r;
  int g;
  int b;
}pixel_t;

int main(){
  pixel_t **M1,**M2,**IMG;
  int C1,L1,C2,L2,M,i,j,maior,soma_L;
  char  P[5];

  /*Lê a primeira imagem*/
  scanf("%s",P);
  scanf("%d",&C1);
  scanf("%d",&L1);
  scanf("%d",&M);

    /*Aloca primeira matriz*/
    M1=(pixel_t **)malloc(L1*sizeof(pixel_t*));
    if(M1==NULL){
      printf("erro na alocacao");
      return 1;
    }
  for(i=0;i<L1;i++){
    M1[i]=(pixel_t *)malloc(C1*sizeof(pixel_t));
    if(M1[i]==NULL){
      printf("erro na alocacao");
      return 1;
    }
    }
  /*Fim da Alocação*/

  for(i=0;i<L1;i++){
    for(j=0;j<C1;j++){
      scanf("%d",&M1[i][j].r);
      scanf("%d",&M1[i][j].g);
      scanf("%d",&M1[i][j].b);
    }
  }
  /*Fim da leitura*/

  /*L� a segunda imagem*/
  scanf("%s",P);
  scanf("%d",&C2);
  scanf("%d",&L2);
  scanf("%d",&M);

  /*Aloca a segunda matriz*/
    M2=(pixel_t **)malloc(L2*sizeof(pixel_t*));
    if(M2==NULL){
      printf("erro na alocacao");
      return 1;
    }
  for(i=0;i<L2;i++){
    M2[i]=(pixel_t *)malloc(C2*sizeof(pixel_t));
     if(M2[i]==NULL){
      printf("erro na alocacao");
      return 1;
    }
    }
  /*Fim da aloca��o*/

  for(i=0;i<L2;i++){
    for(j=0;j<C2;j++){
      scanf("%d",&M2[i][j].r);
      scanf("%d",&M2[i][j].g);
      scanf("%d",&M2[i][j].b);
    }
  }
  /*Fim da leitura*/

  soma_L=L1+L2;
  maior=C1;
  if(C2>C1){
    maior=C2;
  }

  /*Aloca a ultima matriz*/
    IMG=(pixel_t **)malloc(soma_L*sizeof(pixel_t*));
     if(IMG==NULL){
      printf("erro na alocacao");
      return 1;
    }
  for(i=0;i<soma_L;i++){
    IMG[i]=(pixel_t *)malloc(maior*sizeof(pixel_t));
     if(IMG[i]==NULL){
      printf("erro na alocacao");
      return 1;
    }
  }
  /*Fim da aloca��o*/

  /*Junta as duas matrizes*/

   for(i=0;i<L1;i++){
     for(j=0;j<maior;j++){
       if(j>=C1){
	 IMG[i][j].r=M;
	 IMG[i][j].g=M;
	 IMG[i][j].b=M;
       }else{
	 IMG[i][j].r=M1[i][j].r;
	 IMG[i][j].g=M1[i][j].g;
	 IMG[i][j].b=M1[i][j].b;
       }

     }
   }

   for(i=0;i<L2;i++){
     for(j=0;j<maior;j++){
       if(j>=C2){
	 IMG[L1+i][j].r=M;
	 IMG[L1+i][j].g=M;
	 IMG[L1+i][j].b=M;
       }else{
	 IMG[L1+i][j].r=M2[i][j].r;
	 IMG[L1+i][j].g=M2[i][j].g;
	 IMG[L1+i][j].b=M2[i][j].b;
       }

     }
   }

   /*Imprime a imagem na tela*/
   printf("%s\n",P);
   printf("%d %d\n",maior,soma_L);
   printf("%d\n",M);

   for(i=0;i<soma_L;i++){
     for(j=0;j<maior;j++){
       printf("%d\n",IMG[i][j].r);
       printf("%d\n",IMG[i][j].g);
       printf("%d\n",IMG[i][j].b);
     }
   }

   /*desaloca as matrizes*/

  for(i=0;i<L1;i++){
    free(M1[i]);
  }
  free(M1);

  for(i=0;i<L2;i++){
    free(M2[i]);
  }
  free(M2);

  for(i=0;i<soma_L;i++){
    free(IMG[i]);
  }
  free(IMG);


return 0;
}
