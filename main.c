#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	int coluna = 1;
	char linha = 'd';
	int bloco[4][4];
	int bomb;
	char charLinha;
	int intColuna, intLinha, charColuna;


	srand(time(NULL));                                 //GERACAO DAS BOMBAS{
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			bomb = rand() % 3 + 1;
			if(bomb == 1){
				bloco[i][j]++;
			}
		}
	}                                                   //}

	do{

		for(int i = 0; i < 4; i++){                          //GERACAO DA TELA{
			printf("%c   ", linha);
			linha--;
			for(int j = 0; j < 4; j++){
				printf("%i ", bloco[i][j]);
			}
			printf("\n");
		}
		printf("\n    ");
		for(int i = 0; i < 4; i++){
			printf("%i ", coluna);
			coluna++;
		}                                                     //}


		printf("\n");
		do{                                                      //ADQUIRIR LOCAL DA MATRIZ{
			printf("Digite a linha: (a - b - c - d)\n");
			fflush(stdin);
			scanf("%c", &charLinha);
			getchar();
				switch(charLinha){
				case 'a':
					intLinha = 3;
					break;
				case 'b':
					intLinha = 2;
					break;
				case 'c':
					intLinha = 1;
					break;
				case 'd':
					intLinha = 0;
					break;
				}
		}while(intLinha < 0 || intLinha > 3);

		do{
			printf("Digite a coluna: (1 - 2 - 3 - 4)\n");
			scanf("%i", &charColuna);
				switch(charColuna){
				case 1:
					intColuna = 0;
					break;
				case 2:
					intColuna = 1;
					break;
				case 3:
					intColuna = 2;
					break;
				case 4:
					intColuna = 3;
					break;
				}
		}while(intColuna < 0 || intColuna > 3);                           //}

		if(bloco[intLinha][intColuna] != 1){
			printf("Ufa! Não era uma bomba!\n\n");
		}

		coluna = 1;
		linha = 'd';

	}while(bloco[intLinha][intColuna] != 1);

	printf("Que pena! Você perdeu :(");

	return 0;
}
