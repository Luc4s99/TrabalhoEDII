/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autores: Lucas Mateus Menezes Silva - 0035334
/ 		   Breno Nunes Batista - 0035325
*************************************************************************************************************************************/

#ifndef TADGrafo_H
#define TADGrafo_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definição do Tipo Abstrato de Dados*/
typedef struct controlerotas{//Vetor para o controle da matriz de rotas
	char abreviacao[4];
}controleRotas;

typedef struct voos{//Estrutura para os voos
	int numParadas;//
	int duracao;//Duração dos voos em minutos
}Voos;

typedef struct voo{
	Voos *numVoos;
	int qtdVoos;
}Voo;

FILE *file;//Ponteiro para arquivos

/*Matrizes e vetor para voos e rotas*/
controleRotas *vetorRotas;

int **MatrizRotas;
Voo **MatrizVoos;

/*Funções*/
void GeraGrafos(controleRotas *vetorRotas, int **MatrizRotas);//Função para popular as estruturas de rotas

#endif