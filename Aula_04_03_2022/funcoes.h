// header file funcoes.h
#include <stdio.h>

#define MAXNOME 40	

typedef enum { F, T } bool;	///Boolean

typedef struct {
	char nome[MAXNOME];	// Designação do Objeto
	float dist;	        // Distancia do objeto
}Objeto;

// Inserção de um novo objeto
bool inserirObjeto(Objeto *lista, int *end_n, int qt, char nome[], float d);

// Devolve a média das distância
float MediaDistanciaObjetos(Objeto *lista, int n);

// Devolve o endereço de memória do objeto mais distante
Objeto* QualMaisLonge(Objeto *lista, int n);

// Guardar em ficheiro
bool GravaDados(char*nomeFicheiro, Objeto *lista, int n);

// Ler ficheiro
Objeto* LeDados(char* nomeFicheiro);

