// header file funcoes.h
#include <stdio.h>

#define MAXNOME 40	

typedef enum { F, T } bool;	///Boolean

typedef struct {
	char nome[MAXNOME];	// Designa��o do Objeto
	float dist;	        // Distancia do objeto
}Objeto;

// Inser��o de um novo objeto
bool inserirObjeto(Objeto *lista, int *end_n, int qt, char nome[], float d);

// Devolve a m�dia das dist�ncia
float MediaDistanciaObjetos(Objeto *lista, int n);

// Devolve o endere�o de mem�ria do objeto mais distante
Objeto* QualMaisLonge(Objeto *lista, int n);

// Guardar em ficheiro
bool GravaDados(char*nomeFicheiro, Objeto *lista, int n);

// Ler ficheiro
Objeto* LeDados(char* nomeFicheiro);

