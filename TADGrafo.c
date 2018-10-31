/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autor: Lucas Mateus Menezes Silva - 0035334
*************************************************************************************************************************************/

#include "TADGrafo.h"

void GeraGrafoRotas(){
	char leitura, lixo[5]; 
	int numAero = 0;

	file = fopen("InfoVoo.txt", "r");//Abrindo arquivo para a leitura dos dados
	if (file == NULL){//Verificando se foi possível abrir o arquivo
		printf("Falha na abertura do arquivo");
		getchar();
		exit(1);
	}
	fscanf(file, "%c", &leitura);//Lendo o Primeiro caracter do arquivo
	while(leitura != '!'){//Se o caracter lido for diferente de '!', então'ele identifica um aeroporto
		numAero++;//Numero de aeroportos é incrementado
		fscanf(file, "%[^\n]s", lixo);
		fscanf(file, "%c", &leitura);		
		fscanf(file, "%c", &leitura);
		getchar();
	}
	printf("Deu certo\n");
}