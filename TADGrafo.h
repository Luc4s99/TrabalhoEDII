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
#include <ctype.h>

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

int **MatrizRotas;//Matriz para as rotas
Voo **MatrizVoos;//Matriz para os voos
Voos **MatrizMinima;//Matriz contendo somente o voos minimos entre cada aeroporto

int TamanhoVetorRotas;
int numAero;

/*Funções*/
void GeraGrafos();//Função para popular as estruturas de rotas
void GeraDotRotas();//Função para a geração do arquivo dot utilizado para a geração do arquivo do grafo
void MenorCaminho();
void GeraMatrizMinima();//Gera a matriz com os voos minimos entre cada aeroporto
void VoosDiretos(int indice);
#endif