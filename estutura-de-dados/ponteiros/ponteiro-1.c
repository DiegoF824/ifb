#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	int l,c;
	int i,j;
	srand(time(NULL));
	printf("Digite o número de linhas da matriz: ");
	scanf("%d",&l);
	printf("Digite o número de colunas da matriz: ");
	scanf("%d",&c);

	int** m = calloc(l,sizeof(int*));
	if(m==NULL){
		printf("Erro na alocação.\n");
		exit(EXIT_FAILURE);
	}

	m[0] = calloc(l*c,sizeof(int));
	if(m[0]==NULL){
		printf("Erro na alocação.\n");
		exit(EXIT_FAILURE);
	}

	for(j=1;j<l;j++){
		m[j] = m[0]+j*c;
	}
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			m[i][j] = rand() % 1000;
		}
	}

	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%3d ",m[i][j]);
		}
		printf("\n");
	}

	free(m[0]);
	free(m);

	return 0;
}