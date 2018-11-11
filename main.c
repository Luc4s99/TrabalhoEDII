/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autor: Lucas Mateus Menezes Silva - 0035334
*************************************************************************************************************************************/

#include "TADGrafo.h"

int main(){
	int opcao, indice1, indice2;
	char sigla[4], sigla2[4], sigla3[4];

	GeraGrafos();
	GeraDotRotas();

	while(1){
		system("cls");
		system("clear");
		printf("\t::::: GERECIADOR DE ROTAS E VOOS :::::\n\n");
		printf("1 - Mostrar caminho entre dois aeroportos\n\n2 - Mostrar voos de um determinado aeroporto\n\n3- Voo com menor duração entre dois aeroportos\n\n4- Aeroporto fora de servico\n\n5- Arvore Geradora Minima\n\n\tOpcao: ");
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
				setbuf(stdin, NULL);
				getchar();

			break;

			case 3:
				GeraMatrizMinima();
				do{
					printf("\nSigla do aeroporto de origem: \n");
					scanf("%s", sigla);
				}while(ProcuraSigla(sigla) == -1);

				do{
					printf("\nSigla do aeroporto de destino: \n");
					scanf("%s", sigla2);
				}while(ProcuraSigla(sigla2) == -1);
				
				if(ProcuraSigla(sigla) == ProcuraSigla(sigla2)){
					printf("O aeroporto de destino é o mesmo aeroporto de origem\n");
					break;
				}

				FloydWarshall();//Invocando a função de Floyd Warshall
				printf("\n\nO caminho minimo entre %s e %s requer: %d minutos de duração\n\n", sigla, sigla2, MatrizMinima[ProcuraSigla(sigla)][ProcuraSigla(sigla2)]);
			  	setbuf(stdin, NULL);
			  	getchar();

			break;

			case 4:
				GeraMatrizMinima();
				do{
					printf("\nSigla do aeroporto de origem: \n");
					scanf("%s", sigla);
				}while(ProcuraSigla(sigla) == -1);

				do{
					printf("\nSigla do aeroporto de destino: \n");
					scanf("%s", sigla3);
				}while(ProcuraSigla(sigla3) == -1);

				if(ProcuraSigla(sigla) == ProcuraSigla(sigla3)){
					printf("O aeroporto de destino e o mesmo aeroporto de origem\n");
					setbuf(stdin, NULL);
					getchar();
					break;
				}

				do{
					printf("\nSigla do aeroporto fora de operação: \n");
					scanf("%s", sigla2);
				}while(ProcuraSigla(sigla2) == -1);

				if(ProcuraSigla(sigla) == ProcuraSigla(sigla2)){
					printf("O aeroporto de origem e o mesmo aeroporto fora de operacao\n");
					setbuf(stdin, NULL);
					getchar();
					break;
				}else if(ProcuraSigla(sigla2) == ProcuraSigla(sigla3)){
					printf("O aeroporto de destino e o mesmo aeroporto fora de operacao\n");
					setbuf(stdin, NULL);
					getchar();
					break;
				}

				for(int i = 0; i < numAero; i++){//Varre a quantidade de vértices na matriz de adjacencia
					MatrizMinima[i][ProcuraSigla(sigla2)] = INFINITY;//Coloca a coluna do aeroporto fora de operacao invalida
					MatrizMinima[ProcuraSigla(sigla2)][i] = INFINITY;//Coloca a linha do aeroporto fora de operação invalida
				}

				FloydWarshall();//Invocando a função de Floyd Warshall
				printf("\n\nO caminho minimo entre %s e %s, com o aeroporto %s fora de operação, requer: %d minutos de duração\n\n", sigla, sigla3, sigla2, MatrizMinima[ProcuraSigla(sigla)][ProcuraSigla(sigla3)]);
				setbuf(stdin, NULL);
				getchar();

			break;

			case 5:
				Kruskal(0);
			break;

			default:
				exit(1);
		}
	}
	return 0;
}