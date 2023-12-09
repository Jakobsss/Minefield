#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	//Declarações
	int coluna = 1;
	char linha = 'd';
	int bloco[4][4];
	char tela[4][4] = {{'?', '?', '?', '?'}, {'?', '?', '?', '?'}, {'?', '?', '?', '?'}, {'?', '?', '?', '?'}};
	int bomb;
	char charLinha;
	int intColuna, intLinha, charColuna;
	int blocosDescobertos, totalBlocosDescobertos;
	blocosDescobertos = 0;
	totalBlocosDescobertos = 0;

	//Geração das bombas
	srand(time(NULL));
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			bomb = rand() % 3 + 1;
			if(bomb == 1){
				bloco[i][j] = -1;
			}else{
				totalBlocosDescobertos++;
			}
		}
	}

	//Checagem das bombas
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(bloco[i][j] != -1){
				if(i - 1 >= 0 && i - 1 < 4 && j >= 0 && j < 4 && bloco[i - 1][j] == -1){
					bloco[i][j]++;
				}
				if(i - 1 >= 0 && i - 1 < 4 && j + 1 >= 0 && j + 1 < 4 && bloco[i - 1][j + 1] == -1){
					bloco[i][j]++;
				}
				if(i >= 0 && i < 4 && j + 1 >= 0 && j + 1 < 4 && bloco[i][j + 1] == -1){
					bloco[i][j]++;
				}
				if(i + 1 >= 0 && i + 1 < 4 && j + 1 >= 0 && j + 1 < 4 && bloco[i + 1][j + 1] == -1){
					bloco[i][j]++;
				}
				if(i + 1 >= 0 && i + 1 < 4 && j >= 0 && j < 4 && bloco[i + 1][j] == -1){
					bloco[i][j]++;
				}
				if(i + 1 >= 0 && i + 1 < 4 && j - 1 >= 0 && j - 1 < 4 && bloco[i + 1][j - 1] == -1){
					bloco[i][j]++;
				}
				if(i >= 0 && i < 4 && j - 1 >= 0 && j - 1 < 4 && bloco[i][j - 1] == -1){
					bloco[i][j]++;
				}
				if(i - 1 >= 0 && i - 1 < 4 && j - 1 >= 0 && j - 1 < 4 && bloco[i - 1][j - 1] == -1){
					bloco[i][j]++;
				}
			}
		}
	}

	intLinha = -10;
	intColuna = -10;

	//Geração da tela
	do{

		for(int i = 0; i < 4; i++){
			printf("%c  ", linha);
			linha--;
			for(int j = 0; j < 4; j++){
				if(i == intLinha && j == intColuna){
					printf("%i ", bloco[i][j]);
					tela[i][j] = '0' + bloco[i][j];
				}else{
					printf("%c ", tela[i][j]);
				}
			}
			printf("\n");
		}


		printf("\n   ");
		for(int i = 0; i < 4; i++){
			printf("%i ", coluna);
			coluna++;
		}

		//Adquirir local da matriz
		printf("\n");
		do{
			printf("Digite a linha: (a - b - c - d)\n");
			scanf(" %c", &charLinha);
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
				default:
					printf("Linha inválida. Tente novamente.\n");
				}
		}while(charLinha < 'a' || charLinha > 'd');

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
				default:
					printf("Coluna inválida. Tente novamente.\n");
				}
		}while(charColuna < 1 || charColuna > 4);								//}

		if(bloco[intLinha][intColuna] != -1){
			blocosDescobertos++;
		}

		coluna = 1;
		linha = 'd';

	}while(bloco[intLinha][intColuna] != -1 && totalBlocosDescobertos != blocosDescobertos);

	//Checagem se ganhou ou perdeu
	if(totalBlocosDescobertos == blocosDescobertos){
		printf("Parabéns! Você venceu!");
	}else{
		printf("Que pena! Você perdeu :(");
	}

	return 0;
}


