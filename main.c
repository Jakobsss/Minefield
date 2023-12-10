#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	int blocos[4][4];
	char tela[4][4];
}Matriz;

typedef struct{
	int limpos;
	int sujos;
	int descobertos;
}Blocos;

typedef struct{
	char linha;
	int coluna;
}Resposta;

typedef struct{
	int linha;
	int coluna;
}Index;

int main(){
	//Declarações de structs
	Matriz matriz = {{{0}}, {{'?', '?', '?', '?'}, {'?', '?', '?', '?'}, {'?', '?', '?', '?'}, {'?', '?', '?', '?'}}};
	Blocos blocos = {0, 0, 0};
	Resposta resposta = {'a', 0};
	Index index = {0, 0};

	//Declarações de ponteiros de structs
	Matriz *pMatriz = &matriz;
	Blocos *pBlocos = &blocos;
	Resposta *pResposta = &resposta;
	Index *pIndex = &index;

	//Declarações de funções
	void gerarBombas(Matriz *pMatriz, Blocos *pBlocos);
	void checarArredores(Matriz *pMat);
	void adquirirLinha(Resposta *pResposta, Index *pIndex);
	void adquirirColuna(Resposta *pResposta, Index *pIndex);

	int coluna = 1;
	char linha = 'd';

	//Gerar Bombas
	srand(time(NULL));
	gerarBombas(pMatriz, pBlocos);


	//Checagem dos arredores
	checarArredores(pMatriz);

	index.linha = -10;
	index.coluna = -10;

	//Geração da tela
	do{

		for(int i = 0; i < 4; i++){
			printf("%c  ", linha);
			linha--;
			for(int j = 0; j < 4; j++){
				if(i == index.linha && j == index.coluna){
					printf("%i ", matriz.blocos[i][j]);
					matriz.tela[i][j] = '0' + matriz.blocos[i][j];
				}else{
					printf("%c ", matriz.tela[i][j]);
				}
			}
			printf("\n");
		}


		printf("\n   ");
		for(int i = 0; i < 4; i++){
			printf("%i ", coluna);
			coluna++;
		}
		printf("\n");

		//Adquirir linha da matriz
		adquirirLinha(pResposta, pIndex);

		//Adquirir coluna da matriz
		adquirirColuna(pResposta, pIndex);

		if(matriz.blocos[index.linha][index.coluna] != -1){
			blocos.descobertos++;
		}

		coluna = 1;
		linha = 'd';

	}while(matriz.blocos[index.linha][index.coluna] != -1 && blocos.limpos != blocos.descobertos);

	//Checagem se ganhou ou perdeu
	if(blocos.limpos == blocos.descobertos){
		printf("Parabéns! Você venceu!");
	}else{
		printf("Que pena! Você perdeu :(");
	}

	return 0;
}

void gerarBombas(Matriz *pMatriz, Blocos *pBlocos){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if((rand() % 3 + 1) == 1){
				pMatriz->blocos[i][j] = -1;
				pBlocos->sujos++;
			}else{
				pBlocos->limpos++;
			}
		}
	}
}

void checarArredores(Matriz *pMatriz){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(pMatriz->blocos[i][j] != -1){
				if(i - 1 >= 0 && i - 1 < 4 && j >= 0 && j < 4 && pMatriz->blocos[i - 1][j] == -1){
					pMatriz->blocos[i][j]++;
				}
				if(i - 1 >= 0 && i - 1 < 4 && j + 1 >= 0 && j + 1 < 4 && pMatriz->blocos[i - 1][j + 1] == -1){
					pMatriz->blocos[i][j]++;
				}
				if(i >= 0 && i < 4 && j + 1 >= 0 && j + 1 < 4 && pMatriz->blocos[i][j + 1] == -1){
					pMatriz->blocos[i][j]++;
				}
				if(i + 1 >= 0 && i + 1 < 4 && j + 1 >= 0 && j + 1 < 4 && pMatriz->blocos[i + 1][j + 1] == -1){
					pMatriz->blocos[i][j]++;
				}
				if(i + 1 >= 0 && i + 1 < 4 && j >= 0 && j < 4 && pMatriz->blocos[i + 1][j] == -1){
					pMatriz->blocos[i][j]++;
				}
				if(i + 1 >= 0 && i + 1 < 4 && j - 1 >= 0 && j - 1 < 4 && pMatriz->blocos[i + 1][j - 1] == -1){
					pMatriz->blocos[i][j]++;
				}
				if(i >= 0 && i < 4 && j - 1 >= 0 && j - 1 < 4 && pMatriz->blocos[i][j - 1] == -1){
					pMatriz->blocos[i][j]++;
				}
				if(i - 1 >= 0 && i - 1 < 4 && j - 1 >= 0 && j - 1 < 4 && pMatriz->blocos[i - 1][j - 1] == -1){
					pMatriz->blocos[i][j]++;
				}
			}
		}
	}
}

void adquirirLinha(Resposta *pResposta, Index *pIndex){
	do{
		printf("Digite a linha: (a - b - c - d)\n");
		scanf(" %c", &pResposta->linha);
			switch(pResposta->linha){
			case 'a':
				pIndex->linha = 3;
				break;
			case 'b':
				pIndex->linha = 2;
				break;
			case 'c':
				pIndex->linha = 1;
				break;
			case 'd':
				pIndex->linha = 0;
				break;
			default:
				printf("Linha inválida. Tente novamente.\n");
			}
	}while(pResposta->linha < 'a' || pResposta->linha > 'd');
}

void adquirirColuna(Resposta *pResposta, Index *pIndex){
	do{
		printf("Digite a coluna: (1 - 2 - 3 - 4)\n");
		scanf("%i", &pResposta->coluna);
			switch(pResposta->coluna){
			case 1:
				pIndex->coluna = 0;
				break;
			case 2:
				pIndex->coluna = 1;
				break;
			case 3:
				pIndex->coluna = 2;
				break;
			case 4:
				pIndex->coluna = 3;
				break;
			default:
				printf("Coluna inválida. Tente novamente.\n");
			}
	}while(pResposta->coluna < 1 || pResposta->coluna > 4);
}

