#include<stdio.h>
#include<stdlib.h>

int busca_binaria(int ini,int fim, char nome[20], char inteiro[10]){
   FILE *file;
   int meio,x;
   int a;
   x=atoi(inteiro);
   meio=(fim+ini)/2;
   file=fopen(nome,"r");

   if(fim-ini<=0) return -1;
   fseek(file,10*(meio),SEEK_SET);
   fscanf(file,"%d",&a);
   fclose(file);
   if(a==x) return meio;
   if(x<a) return busca_binaria(ini,meio,nome,inteiro);
   return busca_binaria(meio+1,fim,nome,inteiro);
  }

int main(){
  FILE *file;
  char  nome[20], inteiro[10];
  int n=0,a;

  scanf("%s %s",nome,inteiro);
  
  file=fopen(nome,"r");
  while(fscanf(file,"%d",&a) == 1){
    n++;
  }
 

  fclose(file);

 a=busca_binaria(0,n,nome,inteiro);
 if(a==-1){
   printf("Valor nao encontrado\n");
 }else{
   printf("Valor encontrado na posicao %d\n",a);
 }
  
return 0;
}
