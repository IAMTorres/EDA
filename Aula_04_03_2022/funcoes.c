#include <string.h>
#include "funcoes.h"

// Inserção de um novo objeto
bool inserirObjeto(Objeto *lista, int *end_n, int qt, char *nome, float d)
{
 if (*end_n<qt)
 {strcpy(lista[*end_n].nome,nome);
  lista[*end_n].dist = d;
  (*end_n)++; 
  return(T);
 }
 else return(F);
}

/*
float MediaDistanciaObjetos(Objeto *lista, int n)
{}

Objeto* QualMaisLonge(Objeto *lista, int n)
{}

bool GravaDados(char*nomeFicheiro, Objeto *lista, int n)
{}

Objeto* LeDados(char* nomeFicheiro)
{}
*/

