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

#define INFINITY 30000

/*Definição do Tipo Abstrato de Dados*/
typedef struct controlerotas{//Vetor para o controle da matriz de rotas
	char abreviacao[4];
}controleRotas;

typedef struct voos{//Estrutura para os voos
	int numParadas;//
	int duracao;//Duração dos voos em minutos
	int grau;
}Voos;

typedef struct voo{//Estrtura para diversos voos entre dois aeroportos
	Voos *numVoos;
	int qtdVoos;//Quantidade de voos entre os dois aeroportos
}Voo;

FILE *file;//Ponteiro para arquivos

/*Matrizes e vetor para voos e rotas*/
controleRotas *vetorRotas;
int *pai;//Vetor usado no algoritmo do menor caminho para salvar os caminhos
int *duracao;//Vetor com a duração dos caminhos usado na função de caminhos minimos

int **MatrizRotas;//Matriz para as rotas
Voo **MatrizVoos;//Matriz para os voos
int **MatrizMinima;//Matriz usada na descoberta do caminho mínimo

int TamanhoVetorRotas;
int numAero;

/*Funções*/
void GeraGrafos();//Função para popular as estruturas de rotas
void GeraGrau();//Gera o grau de cada vértice da matriz
void GeraDotRotas();//Função para a geração do arquivo dot utilizado para a geração do arquivo do grafo
int ProcuraSigla(char *sigla);//Procura  indice de uma determinada sigla
void FloydWarshall();//Função que encontra o caminho minimo entre os vertices
void GeraMatrizMinima();//Gera a matriz com os voos minimos entre cada aeroporto
void VoosDiretos(int indice);//Printa os voos diretos de um aeroporto
#endif