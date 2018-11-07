/*************************************************************************************************************************************
/ Segundo trabalho prático de estrutura de dados II
/ Autores: Lucas Mateus Menezes Silva - 0035334
/ 		   Breno Nunes Batista - 0035325
*************************************************************************************************************************************/

#include "TADGrafo.h"
#define PARADA "!"

void GeraGrafos(){
	char leitura[4], leitura2[4]; 
	int indice1, indice2, numParadas, duracao;

	numAero = 0;
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
  	fgetc(file);//Pulando o \n

	MatrizVoos = (Voo**) malloc(numAero * sizeof(Voo*));//Alocação do primeiro vetor da matriz
	for (int i = 0; i < numAero; i++){ //Percorre as linhas do Vetor de Ponteiros
       MatrizVoos[i] = (Voo*) malloc(numAero * sizeof(Voo)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (int j = 0; j < numAero; j++){ //Percorre o Vetor de Inteiros atual.
            MatrizVoos[i][j].qtdVoos = 0;//Iniciando a quantidade de voos
            MatrizVoos[i][j].numVoos = (Voos*) malloc(sizeof(Voos));//Iniciando o vetor de voos
       }
  	}

  	while(1){
  		fscanf(file, "%s", leitura);//Leitura do aeroporto de origem
  		if(!strcmp(leitura, PARADA)){//Verifica se a leitura recebeu  símbolo de parada
  			break;
  		}
  		fgetc(file);//Pulando um espaço
  		fscanf(file, "%s", leitura2);//Leitura do aeroporto de destino
  		fgetc(file);//Pulando um espaço
  		fscanf(file, "%d", &numParadas);//Leitura da quantidade de paradas
  		fgetc(file);//Pulando um espaço
  		fscanf(file, "%d", &duracao);//Leitura da duração do voo em minutos
  		fgetc(file);//Pulando espaço

  		for(int i = 0; i < numAero; i++){
	  		if (!strcmp(leitura, vetorRotas[i].abreviacao)){//Procurando a abreviação dentro do vetor
	  			indice1 = i;//Salvando o índice
	  		}
  		}
  		for(int i = 0; i < numAero; i++){
	  		if (!strcmp(leitura2, vetorRotas[i].abreviacao)){//Procurando a abreviação dentro do vetor
	  			indice2 = i;
	  		}
  		}
  		if(MatrizVoos[indice1][indice2].qtdVoos == 0){//Caso nenhum voo foi alocado
  			MatrizVoos[indice1][indice2].numVoos->numParadas = numParadas;//Setando o numero de paradas
  			MatrizVoos[indice1][indice2].numVoos->duracao = duracao;//Setando a duração do voo
  			MatrizVoos[indice1][indice2].qtdVoos++;//Incrementando a quantidade de voos para voos com mesma origem e destino
  		}else{//Se já existirim voos alocados
  			MatrizVoos[indice1][indice2].numVoos = (Voos*) realloc(MatrizVoos[indice1][indice2].numVoos, (MatrizVoos[indice1][indice2].qtdVoos + 1) * sizeof(Voos));//Realocando a memória para a quantidade de voos
  			MatrizVoos[indice1][indice2].numVoos[MatrizVoos[indice1][indice2].qtdVoos].numParadas = numParadas;//Setando o número de paradas
  			MatrizVoos[indice1][indice2].numVoos[MatrizVoos[indice1][indice2].qtdVoos].duracao = duracao;//Setando a duração do voo
  			MatrizVoos[indice1][indice2].qtdVoos++;//Incrementando a quantidade de voos
  		}
  	}
  	TamanhoVetorRotas = numAero;

  	fclose(file);//Fechando o arquivo usado
}

void GeraDotRotas(){
	file = fopen("GrafoRotas.dot", "w");
	if(file == NULL){
		printf("Falha na abertura do arquivo");
		exit(1);
	}
	fprintf(file, "graph GrafoRotas {\n");
	for(int i = 0; i < TamanhoVetorRotas; i++){
		for(int j = i; j < TamanhoVetorRotas; j++){
			if(MatrizRotas[i][j] == 1){
				fprintf(file, "\t%s -- %s;\n", vetorRotas[i].abreviacao, vetorRotas[j].abreviacao);
			}
		}
	}
	fprintf(file, "}");
	fclose(file);
}

void GeraMatrizMinima(){
	MatrizMinima = (Voos**) malloc(numAero * sizeof(Voos*));//Alocação do primeiro vetor da matriz
	for (int i = 0; i < numAero; i++){ //Percorre as linhas do Vetor de Ponteiros
       MatrizMinima[i] = (Voos*) malloc(numAero * sizeof(Voos)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (int j = 0; j < numAero; j++){ //Percorre o Vetor de Inteiros atual.
        MatrizMinima[i][j].duracao = 0;
        MatrizMinima[i][j].numParadas = 0;
            for(int k = 0; k < MatrizVoos[i][j].qtdVoos; k++){
            	if(k == 0){
            		MatrizMinima[i][j].duracao = MatrizVoos[i][j].numVoos[k].duracao;
            		MatrizMinima[i][j].numParadas = MatrizVoos[i][j].numVoos[k].numParadas;
            	}else{
            		if(MatrizVoos[i][j].numVoos[k].duracao < MatrizMinima[i][j].duracao){
            			MatrizMinima[i][j].duracao = MatrizVoos[i][j].numVoos[k].duracao;
            			MatrizMinima[i][j].numParadas = MatrizVoos[i][j].numVoos[k].numParadas;	
            		}
            	}
            }
       }
  	}
}

void MenorCaminho(){

}

void VoosDiretos(int indice){//Retorna os voos sem escala de um certo aeroporto
	for(int i = 0; i < numAero; i++){//Percorrendo as colunas da matriz
		if(MatrizVoos[indice][i].qtdVoos > 0){//Se existirem voos naquele índice da matriz
			for(int j = 0; j < MatrizVoos[indice][i].qtdVoos; j++){//Percorrendo o vetor com todos os voos do aeroporto
				printf("Origem: %s - Destino: %s - Paradas: %d - Duracao(minutos): %d\n",vetorRotas[indice].abreviacao, vetorRotas[i].abreviacao, MatrizVoos[indice][i].numVoos[j].numParadas, MatrizVoos[indice][i].numVoos[j].duracao);
			}
		}
	}
	printf("\n");
}