/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autor: Lucas Mateus Menezes Silva - 0035334
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
	int distancia;
	int numParadas;
	float duracao;
}Voos;

FILE *file;//Ponteiro para arquivos

/*Matrizes e vetor para voos e rotas*/
controleRotas *vetorRotas;
int **MatrizRotas;
Voos **MatrizVoos;

/*Funções*/
void GeraGrafoRotas(controleRotas *vetorRotas, int **MatrizRotas);

#endif