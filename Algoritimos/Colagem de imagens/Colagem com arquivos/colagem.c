#include<stdio.h>
#include<string.h>

typedef struct {
  int r;
  int g;
  int b;
}pixel_t;

pixel_t Matriz[1000][1000],Matriz1[1000][1000],Matriz2[2000][2000];
int main(){
  FILE *file;
  FILE *file1;
  FILE *file2;
  int C,L,c1,l1,M,i,j,maior,soma_L;
  char  nome1[10], nome2[10],nome3[20],P[5];

  scanf("%s %s",nome1,nome2);
  strcpy(nome3,nome1);
  strcat(nome3,nome2);

  file=fopen(nome1,"r");
  file1=fopen(nome2,"r");
  file2=fopen(nome3,"w");


  fscanf(file,"%s",P);
  fscanf(file1,"%s",P);
  fprintf(file2,"%s\n",P);

  fscanf(file,"%d",&C);
  fscanf(file,"%d",&L);
  fscanf(file1,"%d",&c1);
  fscanf(file1,"%d",&l1);
  soma_L=L+l1;
  maior=C;
  if(c1>C){
    maior=c1;
  }

  fprintf(file2,"%d %d\n",maior,soma_L);

  fscanf(file,"%d",&M);
  fscanf(file1,"%d",&M);
  fprintf(file2,"%d\n",M);

  /*lê Matriz*/

   for(i=0;i<l1;i++){
    for(j=0;j<c1;j++){
      fscanf(file1,"%d",&Matriz1[i][j].r);
      fscanf(file1,"%d",&Matriz1[i][j].g);
      fscanf(file1,"%d",&Matriz1[i][j].b);
    }
   }
   for(i=0;i<L;i++){
    for(j=0;j<C;j++){
      fscanf(file,"%d",&Matriz[i][j].r);
      fscanf(file,"%d",&Matriz[i][j].g);
      fscanf(file,"%d",&Matriz[i][j].b);
    }
   }
   /*Junta as duas matrizes*/

   for(i=0;i<L;i++){
     for(j=0;j<maior;j++){
       if(j>=C){
	 Matriz2[i][j].r=M;
	 Matriz2[i][j].g=M;
	 Matriz2[i][j].b=M;
       }else{
	 Matriz2[i][j].r=Matriz[i][j].r;
	 Matriz2[i][j].g=Matriz[i][j].g;
	 Matriz2[i][j].b=Matriz[i][j].b;
       }

     }
   }

   for(i=0;i<soma_L;i++){
     for(j=0;j<maior;j++){
       if(j>=c1){
	 Matriz2[L+i][j].r=M;
	 Matriz2[L+i][j].g=M;
	 Matriz2[L+i][j].b=M;
       }else{
	 Matriz2[L+i][j].r=Matriz1[i][j].r;
	 Matriz2[L+i][j].g=Matriz1[i][j].g;
	 Matriz2[L+i][j].b=Matriz1[i][j].b;
       }

     }
   }



   /*Escreve a matriz3 no arquivo*/

   for(i=0;i<soma_L;i++){
     for(j=0;j<maior;j++){
       fprintf(file2,"%d\n",Matriz2[i][j].r);
       fprintf(file2,"%d\n",Matriz2[i][j].g);
       fprintf(file2,"%d\n",Matriz2[i][j].b);
     }
   }


  fclose(file);
  fclose(file1);
  fclose(file2);

return 0;
}
