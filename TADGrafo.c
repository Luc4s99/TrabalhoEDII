/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autores: Lucas Mateus Menezes Silva - 0035334
/ 		   Breno Nunes Batista - 0035325
*************************************************************************************************************************************/

#include "TADGrafo.h"
#define PARADA "!"

void GeraGrafoRotas(controleRotas *vetorRotas, int **MatrizRotas){
	char leitura[3], leitura2[3]; 
	int numAero = 0, indice1, indice2;

	file = fopen("InfoVoo.txt", "r");//Abrindo arquivo para a leitura dos dados
	if (file == NULL){//Verificando se foi possível abrir o arquivo
		printf("Falha na abertura do arquivo");
		getchar();
		exit(1);
	}
	while(1){//Se o caracter lido for diferente de '!', então'ele identifica um aeroporto
		fscanf(file, "%s", leitura);//Lendo o Primeiro caracter do arquivo
		numAero++;//Numero de aeroportos é incrementado
		fgetc(file);
		if(!strcmp(leitura, PARADA)){//Comapara a string lida com o símbolo de paradas
			break;
		}else{
			vetorRotas = (controleRotas*) realloc(vetorRotas, numAero * sizeof(controleRotas));//Realocando o tamanho do vetor
			strcpy(vetorRotas[numAero - 1].abreviacao, leitura);//Copiando a string lida para a string do vetor
		}
	}

	numAero--;//Decremento pois no laço a variável sofre um incremento a mais

	MatrizRotas = (int**) malloc(numAero * sizeof(int*));//Alocação do primeiro vetor da matriz
	for (int i = 0; i < numAero; i++){ //Percorre as linhas do Vetor de Ponteiros
       MatrizRotas[i] = (int*) malloc(numAero * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (int j = 0; j < numAero; j++){ //Percorre o Vetor de Inteiros atual.
            MatrizRotas[i][j] = 0; //Inicializa com 0.
       }
  	}

  	fgetc(file);//Pulando o \n
  	while(1){
  		fscanf(file, "%s", leitura);//Lendo as iniciais do aeroporto de origem
  		if(!strcmp(leitura, PARADA)){//Caso ache o caracter de parada
  			break;
  		}
  		for(int i = 0; i < numAero; i++){//For para capturar o indice da abreviação no vetor
  			if (!strcmp(leitura, vetorRotas[i].abreviacao)){//Procurando a abreviação dentro do vetor
  				indice1 = i;//Esse índice será usado para os cálculos de posição da matriz
  			}
  		}
  		fscanf(file, "%s", leitura2);//Lendo a segunda abreviação
  		for(int i = 0; i < numAero; i++){
  			if(!strcmp(leitura2, vetorRotas[i].abreviacao)){//Procurando pela abreviação dentro do vetor
  				indice2 = i;
  			}
  		}  		
  		fgetc(file);//Pulando \n
  		MatrizRotas[indice1][indice2] = 1;//Colocando a rota na matriz
  		MatrizRotas[indice2][indice1] = 1;//A rota contrária também existe
  	}

  	fclose(file);
}