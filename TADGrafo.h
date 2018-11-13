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

#define INFINITY 30000//Valor infinito definido para representar que não existem voos entre dois determinados aeroportos

/*Definição do Tipo Abstrato de Dados*/
typedef struct controlerotas{//Vetor para o controle da matriz de rotas
	char abreviacao[4];//Abreviação do nome de um aeroporto
}controleRotas;

typedef struct voos{//Estrutura para os voos
	int numParadas;//Numero de paradas para aquele voo
	int duracao;//Duração dos voos em minutos
}Voos;

typedef struct voo{//Estrtura para diversos voos entre dois aeroportos
	Voos *numVoos;//Vetor que armazena todos os voos entre dois determinados aeroportos
	int qtdVoos;//Quantidade de voos entre os dois aeroportos
}Voo;

FILE *file;//Ponteiro para arquivos

/*Matrizes e vetor para voos e rotas*/
controleRotas *vetorRotas;//Vetor que possui todas as siglas dos aeroportos lidos no arquivo de entrada, usado para controlar as matrizes
int **matrizResposta;//Matriz utilizada na geração da árvore mínima, contendo a ligação entre os vértices e seus respctivos pesos

int **MatrizRotas;//Matriz para as rotas
Voo **MatrizVoos;//Matriz para os voos
int **MatrizMinima;//Matriz usada na descoberta do caminho mínimo
int numAero;//Possui o número total de aeroportos lidos no arquivo de entrada

/*Funções*/
void GeraGrafos();//Função para popular as estruturas de rotas
void GeraDotRotas();//Função para a geração do arquivo dot utilizado para a geração do arquivo do grafo
int ProcuraSigla(char *sigla);//Procura  indice de uma determinada sigla
void FloydWarshall();//Função que encontra o caminho minimo entre os vertices
void Prim();//Função de geração da árvore mínima
void GeraDotAM();//Gera o arquivo .dot da arvore minima
void RotaAlternativa(int aeroportoDefeito);
void GeraMatrizMinima();//Gera a matriz com os voos minimos entre cada aeroporto
void VoosDiretos(int indice);//Printa os voos diretos de um aeroporto
#endif