#include <stdio.h>

typedef struct Objetos
{
    char nome;
    float dist;
}Objetos;

typedef struct Aux
{
    float media;
    Objetos a;
    Objetos a;
}Aux;


float media(Objetos obj[], int qt)
{
    float soma;
    for(int i=0; i<qt; i++){
        soma += obj[i].dist;
    }
    
    return ((float)soma/qt);
}

float getMaisLonge(Objetos obj[], int qt)
{
    int maior;
    for(int i=0; i<qt; i++){
        if(maior>obj[i].dist) maior=obj[i].dist;
    }
    return maior;
}

float getMaisProximo(Objetos obj[], int qt)
{
    int menor;
    for(int i=0; i<qt; i++){
        if(menor<obj[i].dist) menor=obj[i].dist;
    }
    return menor;
}


Aux getTodasFuncoes(Aux aux, int qt)
{
    Aux.media=float media(Objetos obj[], int qt);
    Objetos getMaisProximo(Objetos obj[], int qt);
    Objetos getMaisLonge(Objetos obj[], int qt);
    return 
}
int main(int argc, char const *argv[])
{
    int qt = 10;
    Objetos obj[10];
    Aux aux;
    Objetos resultado1;
    Aux resultado2;
    resultado1 = media(Objetos obj[], int qt);
    resultado1 = getMaisProximo(Objetos obj[], int qt);
    resultado1 = getMaisLonge(Objetos obj[], int qt);
    resultado2 = getTodasFuncoes(Aux aux,Objetos obj[], int qt);
    return 0;
}

