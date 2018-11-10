/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autor: Lucas Mateus Menezes Silva - 0035334
*************************************************************************************************************************************/

#include "TADGrafo.h"

int main(){
	int opcao, indice1, indice2;
	char sigla[4], sigla2[4];

	GeraGrafos();
	GeraDotRotas();
	GeraMatrizMinima();

	system("cls");
	system("clear");
	printf("\t::::: GERECIADOR DE ROTAS E VOOS :::::\n\n");
	printf("1 - Mostrar caminho entre dois aeroportos\n\n2 - Mostrar voos de um determinado aeroporto\n\n3- Voo com menor duração entre dois aeroportos\n\n\tOpcao: ");
	scanf("%d", &opcao);

	switch(opcao){

		case 1:
			//Dijkstra(0, 10, custos);
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

		case 3:
			do{
				printf("\nAeroporto de origem: \n");
				scanf("%s", sigla);
			}while(ProcuraSigla(sigla) == -1);

			do{
				printf("\nAeroporto de destino: \n");
				scanf("%s", sigla2);
			}while(ProcuraSigla(sigla2) == -1);

			if(MatrizMinima[ProcuraSigla(sigla)][ProcuraSigla(sigla2)] == INFINITY){//Caso a distancia seja infinita, não existe voo
				printf("Nao existe voo entre esses aeroportos\n");
			}else{
				FloydWarshall();//Invocando a função de Floyd Warshall
				printf("\n\nO voo com menor duracao entre %s e %s e de: %d", sigla, sigla2, MatrizMinima[ProcuraSigla(sigla)][ProcuraSigla(sigla2)]);
			}
		  	
		break;

		default:
			exit(1);
	}
	return 0;
}