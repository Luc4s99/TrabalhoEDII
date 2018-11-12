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
  	fclose(file);//Fechando o arquivo usado
}

void GeraDotRotas(){//Gera o arquivo .dot das rotas
	file = fopen("GrafoRotas.dot", "w");
	if(file == NULL){
		printf("Falha na abertura do arquivo");
		exit(1);
	}
	fprintf(file, "graph GrafoRotas {\n");
	for(int i = 0; i < numAero; i++){
		for(int j = i; j < numAero; j++){
			if(MatrizRotas[i][j] == 1){
				fprintf(file, "\t%s -- %s;\n", vetorRotas[i].abreviacao, vetorRotas[j].abreviacao);
			}
		}
	}
	fprintf(file, "}");
	fclose(file);
}

void GeraMatrizMinima(){//Gera uma matriz somente com os menores tempos de voo
	MatrizMinima = (int**) malloc(numAero * sizeof(int*));//Alocação do primeiro vetor da matriz
	for (int i = 0; i < numAero; i++){ //Percorre as linhas do Vetor de Ponteiros
       MatrizMinima[i] = (int*) malloc(numAero * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (int j = 0; j < numAero; j++){ //Percorre o Vetor de Inteiros atual.
        MatrizMinima[i][j] = INFINITY;//Coloca todos os valores como infinito inicialmente
            for(int k = 0; k < MatrizVoos[i][j].qtdVoos; k++){//Percorrendo a matriz na terceira dimensão
            	if(k == 0){//Caso seja a primeira posição
            		MatrizMinima[i][j] = MatrizVoos[i][j].numVoos[k].duracao;//O mínimo é definido como o valor da primeira leitura
            	}else{//Senão os valores deverão ser comparados
            		if(MatrizVoos[i][j].numVoos[k].duracao < MatrizMinima[i][j]){//Caso o valor lido seja menor que  armazenado
            			MatrizMinima[i][j] = MatrizVoos[i][j].numVoos[k].duracao;//Ele é definido como atual
            		}
            	}
            }
       }
  	}
}

int ProcuraSigla(char *sigla){//Procura o índice correspondente a uma certa sigla
	int i = 0;
	while(sigla[i]){//Varre toda a string
		sigla[i] = toupper(sigla[i]);//Coloca todas as letras em caixa alta
		i++;
	}

	for(i = 0; i < numAero; i++){//Procura a String dentro do vetor
		if(!strcmp(vetorRotas[i].abreviacao, sigla)){//Negado pois a função retorna 0 se forem iguais
			return i;//Retorna o índice
		}
	}

	return -1;//Se não encontrar retorna -1
}

void FloydWarshall(){//Função que procura o caminho mínimo entre todos os vértices que possuem conexão
	for(int x = 0; x < numAero; x++){
		for(int y = 0; y < numAero; y++){
			for(int z = 0; z < numAero; z++){
				if( MatrizMinima[y][z] > (MatrizMinima[y][x] + MatrizMinima[x][z])){
					MatrizMinima[y][z] = MatrizMinima[y][x] + MatrizMinima[x][z];
				}
			}	
		}	
	}
}

/*void Prim(int num){//Função de Prim que gera a árvore geradora mínima
	int verticesVerificados[numAero];
	int distanciaRelativa[numAero];
	int nosVizinhos[numAero];

	for(int contador = 0; contador < numAero; contador++){
		verticesVerificados[contador] = -1;
		nosVizinhos[contador] = 0;
		distanciaRelativa[contador] = INFINITY;
	}
	
	distanciaRelativa[0] = 0;

	int pontoAvaliado = num;

	for(int contadorPontoAvaliados = 0; contadorPontoAvaliados < numAero; contadorPontoAvaliados++){
		for(int contadorVizinhos = 0; contadorVizinhos < numAero; contadorVizinhos++){
			if((verticesVerificados[contadorVizinhos]) || (contadorVizinhos == pontoAvaliado)){
				continue;
			}
			if((MatrizMinima[pontoAvaliado][contadorVizinhos] > 0) && (MatrizMinima[pontoAvaliado][contadorVizinhos] < distanciaRelativa[contadorVizinhos])){
				distanciaRelativa[contadorVizinhos] = MatrizMinima[pontoAvaliado][contadorVizinhos];
				nosVizinhos[contadorVizinhos] = pontoAvaliado;
			}
		}
		verticesVerificados[pontoAvaliado] = 1;

		pontoAvaliado = num;
		int distanciaComparada = INFINITY;

		for(int contador = 0; contador < numAero; contador++){
			if(verticesVerificados[contador]){
				continue;
			}

			if(distanciaRelativa[contador] < distanciaComparada){
				distanciaComparada = distanciaRelativa[contador];
				pontoAvaliado = contador;
			}
		}
	}

	for(int contador = 1; contador < numAero; contador++){
		matrizResposta[contador][nosVizinhos[contador]] = MatrizMinima[contador][nosVizinhos[contador]];
		matrizResposta[nosVizinhos[contador]][contador] = matrizResposta[contador][nosVizinhos[contador]];
	}
}*/

void Prim(){
	int *verticesVerificados = malloc(numAero * sizeof(int));
	int *distanciaRelativa = malloc(numAero * sizeof(int));
	int *nosVizinhos = malloc(numAero * sizeof(int));
	int contVV = 0;

	GeraMatrizMinima();

	for(int i = 0; i < numAero; i++){
		verticesVerificados[i] = -1;
		nosVizinhos[i] = 0;
		distanciaRelativa[i] = INFINITY;
	}

	distanciaRelativa[0] = 0;
	int pontoAvaliado = 0;

	for(int i = 0; i < numAero; i++){
		for(int j = 0; j < numAero; j++){
			if(verticesVerificados[j] == 1 || j == pontoAvaliado){
				continue;
			}
			if((MatrizMinima[pontoAvaliado][j] > 0) && ((MatrizMinima[pontoAvaliado][j] < distanciaRelativa[j]))){
				distanciaRelativa[j] = MatrizMinima[pontoAvaliado][j];
				nosVizinhos[j] = pontoAvaliado;
			}
		}
		verticesVerificados[pontoAvaliado] = 1;
		contVV++;
		pontoAvaliado = 0;
		int distanciaComparada = INFINITY;

			for (int i = 0; i < numAero; ++i){
				printf("%d\n", distanciaRelativa[i]);
			}

		for(int k = 1; k < contVV; k++){
			if(!(verticesVerificados[k])){
				continue;
			}
			if(distanciaRelativa[k] <= distanciaComparada){
				distanciaComparada = distanciaRelativa[k];
				pontoAvaliado = k;
			}
		}
	}

  	printf("\n");
  	for(int i = 1; i < numAero; i++){
  		matrizResposta[i][nosVizinhos[i]] = MatrizMinima[i][nosVizinhos[i]];
  		matrizResposta[nosVizinhos[i]][i] = MatrizMinima[i][nosVizinhos[i]];
  	}
}

void GeraDotAM(){//Função que gera o arquivo .dot da árvore mínima
	file = fopen("ArvoreMinima.dot", "w");//Criando o arquivo e colocando a opção "w" de write
	if(file == NULL){//Caso não seja possível criar o arquivo
		printf("Falha na abertura do arquivo");
		exit(1);
	}
	fprintf(file, "graph GrafoRotas {\n");//Printando o primeiro comando para a geração do grafo
	for(int i = 0; i < numAero; i++){//Percorrendo a matriz
		for(int j = i; j < numAero; j++){
			if(matrizResposta[i][j] != INFINITY && matrizResposta[i][j] != 0){
				fprintf(file, "\t%s -- %s [label = ""%d""];\n", vetorRotas[i].abreviacao, vetorRotas[j].abreviacao, matrizResposta[i][j]);//Printa as siglas e a distancia entre os dois aeroportos
			}else{
				continue;
			}
		}
	}
	fprintf(file, "}");//Fechamento dos comandos
	fclose(file);//Fechando o arquivo onde foram feitas as edições
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