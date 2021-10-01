#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int r;
  int g;
  int b;
}pixel_t;

int main(){
  pixel_t **M1,**M2,**IMG;
  FILE *file;
  FILE *file1;
  FILE *file2;
  int C1,L1,C2,L2,M,i,j,maior,soma_L;
  char  nome1[10], nome2[10],P[5];

  scanf("%s %s",nome1,nome2);

  file=fopen(nome1,"r");
  file1=fopen(nome2,"r");
  file2=fopen("saida.ppm","w");


  fscanf(file,"%s",P);
  fscanf(file1,"%s",P);
  fprintf(file2,"%s\n",P);

  fscanf(file,"%d",&C1);
  fscanf(file,"%d",&L1);
  fscanf(file1,"%d",&C2);
  fscanf(file1,"%d",&L2);
  soma_L=L1+L2;
  maior=C1;
  if(C2>C1){
    maior=C2;
  }

  fprintf(file2,"%d %d\n",maior,soma_L);

  fscanf(file,"%d",&M);
  fscanf(file1,"%d",&M);
  fprintf(file2,"%d\n",M);
  /*aloca matriz1*/
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
   
    /* aloca matriz2*/
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
  /*aloca matriz3*/
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


  /*lê Matriz*/

   for(i=0;i<L1;i++){
    for(j=0;j<C1;j++){
      fscanf(file,"%d",&M1[i][j].r);
      fscanf(file,"%d",&M1[i][j].g);
      fscanf(file,"%d",&M1[i][j].b);
      }
   }
   for(i=0;i<L2;i++){
    for(j=0;j<C2;j++){
      fscanf(file1,"%d",&M2[i][j].r);
      fscanf(file1,"%d",&M2[i][j].g);
      fscanf(file1,"%d",&M2[i][j].b);
    }
   }
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

   /*Escreve a matriz3 no arquivo*/
   
   for(i=0;i<soma_L;i++){
     for(j=0;j<maior;j++){
       fprintf(file2,"%d\n",IMG[i][j].r);
       fprintf(file2,"%d\n",IMG[i][j].g);
       fprintf(file2,"%d\n",IMG[i][j].b);
     }
   }


  fclose(file);
  fclose(file1);
  fclose(file2);

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
