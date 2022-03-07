// header file funcoes.h
#include <stdio.h>

#define MAXNOME 40	

typedef enum { F, T } bool;	///Boolean

typedef struct {
	char nome[MAXNOME];	// Designa��o do Objeto
	float dist;	        // Distancia do objeto
}Objeto;
