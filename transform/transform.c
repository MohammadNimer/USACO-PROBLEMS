/*
ID: mohamma71
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho;

void rotate(char *transform);

void reflection(char *transform);

int comparaMatriz(char *comparada,char *manipulada);

void copiaMatriz(char *matriz1,char *matriz2);

int main(){
	FILE *arq=fopen("transform.in","r"),*arq2=fopen("transform.out","w");
	int i=0,j,k=0,cont=0;
	char *Vantes=NULL,*Vdepois=NULL,buffer[15],*buff=NULL;
	
	fscanf(arq,"%d\n",&tamanho);
	printf("%d\n",tamanho);	

	Vantes  = malloc(tamanho*tamanho*sizeof(char));
	Vdepois = malloc(tamanho*tamanho*sizeof(char));
	buff    = malloc(tamanho*tamanho*sizeof(char));
	
	if(tamanho<=10 && tamanho>0){  //COPIA DO ARQUIVO PARA 2 MATRIZES
		while(i<tamanho*2){
			fgets(buffer,tamanho+3,arq);
			if(i<tamanho){
				for(j=0;j<tamanho;j++){
					Vantes[i*tamanho+j] = buffer[j];
					buff[i*tamanho+j]=buffer[j];
					printf("%c",Vantes[i*tamanho+j]);
				}
				printf("\n");
			}else{
				printf("\n");
				for(j=0;j<tamanho;j++){
					Vdepois[k*tamanho+j]=buffer[j];
					printf("%c",Vdepois[k*tamanho+j]);
				}
				k++;
			}
			i++;
		}
	}
	
	printf("\n\n");
	switch(13){
        case 13:
		 	 for(i=1;i<=3;i++){
					rotate(buff);
			 		cont=comparaMatriz(Vdepois,buff);
			 		if(cont/tamanho == tamanho){
						printf("Rotate OPCAO %d\n",i*90);
						fprintf(arq2,"%d\n",i);
						exit(0);
					}
					printf("\n");
			 }
        case 4:
			 copiaMatriz(buff,Vantes);
			 reflection(buff);
			 cont=comparaMatriz(Vdepois,buff);
			 if(cont/tamanho == tamanho){
				 printf("Reflection");
				 fprintf(arq2,"%d\n",4);
				 exit(0);
			 }
        case 5:
			 copiaMatriz(buff,Vantes);
			 reflection(buff);
             for(i=1;i<=tamanho;i++){
				 rotate(buff);
				 cont=comparaMatriz(Vdepois,buff);
				 if(cont/tamanho == tamanho){
					 printf("Combination");
					 fprintf(arq2,"%d\n",5);
					 exit(0);
				 }
			 }
        case 6:
			 cont=comparaMatriz(Vdepois,Vantes);
			 if(cont/tamanho == tamanho){
				 printf("No Change");
				 fprintf(arq2,"%d\n",6);
				 exit(0);
			 }
        case 7:
			 printf("Invalid Transformation!");
			 fprintf(arq2,"%d\n",7);
    }
    return 0;
}

void rotate(char *transform){
    char buff[tamanho][tamanho];
    int i,j,cont;
    cont=tamanho-1;
    for(i=0;i<tamanho;i++){ 
		for(j=0;j<tamanho;j++){
			buff[i][j]= transform[( (cont-j)*tamanho ) + i];
        }
	}
	copiaMatriz(transform,*buff);
}

void reflection(char *transform){
    char buff[tamanho][tamanho];
    int i,j,cont;
    for(i=0;i<tamanho;i++){
        cont=tamanho-1;
        for(j=0;j<tamanho;j++){
            buff[i][j]=transform[i*tamanho+(cont-j)];
        }
    }
    copiaMatriz(transform,*buff);
}

int comparaMatriz(char *comparada,char *manipulada){
	int i,j,cont=0;
	for(j=0;j<tamanho;j++){
		for(i=0;i<tamanho;i++){
			if(comparada[j*tamanho+i] == manipulada[j*tamanho + i]){
				cont++;
			}
		}
	}
	return cont;
}

void copiaMatriz(char *matriz1,char *matriz2){
	int i,j;
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			matriz1[i*tamanho+j]=matriz2[i*tamanho+j];
		}
	}
}
