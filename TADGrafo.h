/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autor: Lucas Mateus Menezes Silva - 0035334
*************************************************************************************************************************************/

#ifndef TADGrafo_H
#define TADGrafo_H

#include <stdio.h>
#include <stdlib.h>

/*Definição do Tipo Abstrato de Dados*/
typedef struct rotas{//Estrutura para as rotas
	int distancia;
	int numParadas;
	float duracao;
}Rotas;

typedef struct voos{//Estrutura para os voos
	int distancia;
	int numParadas;
	float duracao;
}Voos;

FILE *file;//Ponteiro para arquivos

/*Matrizes para voos e rotas*/
Rotas **MatrizRotas;
Voos **MatriVoos;

#endif