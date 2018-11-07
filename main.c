/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autor: Lucas Mateus Menezes Silva - 0035334
*************************************************************************************************************************************/

#include "TADGrafo.h"

int main(){
	int opcao;
	char sigla[4];

	GeraGrafos();
	GeraDotRotas();
	GeraMatrizMinima();

	system("cls");
	system("clear");
	printf("\t::::: GERECIADOR DE ROTAS E VOOS :::::\n\n");
	printf("1 - Mostrar caminho entre dois aeroportos\n\n2 - Mostrar voos de um determinado aeroporto\n\n\tOpcao: ");
	scanf("%d", &opcao);

	switch(opcao){

		case 1:
			
		break;

		case 2:
			printf("Digite a sigla do aeroporto: ");
			scanf("%s", sigla);

			int i = 0;
			while(sigla[i]){
				sigla[i] = toupper(sigla[i]);
				i++;
			}
			for(i = 0; i < numAero; i++){
				if(!strcmp(vetorRotas[i].abreviacao, sigla)){
					VoosDiretos(i);
				}
			}

		break;

		default:
			exit(1);
	}
	return 0;
}