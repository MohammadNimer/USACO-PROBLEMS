/*
ID: mohamma71
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct beads{
       int TotBeads;
}beads[1];

main(){
       int cont=0,numBeads,TOTAL;
       char SeqBeads[350];
       FILE *arq=fopen("beads.txt","r");
       FILE *arq2=fopen("beads1.txt","w");

       fscanf(arq,"%d ",&numBeads);
       
       if(numBeads<3 || numBeads>350){
             exit(0);
       }
      
       while(cont<numBeads){
             SeqBeads[cont]=fgetc(arq);
             SeqBeads[cont+numBeads]=SeqBeads[cont];
             SeqBeads[cont+numBeads+numBeads]=SeqBeads[cont];
             printf("%c",SeqBeads[cont]);
             cont++;  
       }
       printf("\n");
       TOTAL=compara(&SeqBeads,numBeads);
       printf("\n");       
       fprintf(arq2,"%d\n",TOTAL);
       fclose(arq);
       system("pause");
}

int compara(char s[],int nbeads){
    int contR=0,contB=0,tempTotal,Total=0;
    int i,j,z=0,x=0,y;                     //INCREMENTADORES
 
    for(i=nbeads;i<=2*nbeads;i++){                                  //CONTA A PRIMEIRA OCORRENCIA PARA FRENTE
    
            while(s[i]=='w' || s[i+1]=='w' || s[i]==s[i+1]){
                            contB++;
                            
            }
            printf("%d",contB);
            
    }

    printf("\n%d",Total);
return Total;
}
