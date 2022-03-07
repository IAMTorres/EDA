#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	int qt;
	bool resultado;
	printf("Quantidade de objetos a inserir?\n");
	scanf("%d",&qt);
/*
	int a = 10;
	int *b = &a; // atribuição do endereço de memória da variável a à variável b
	int c = *b; // atribuição do valor inteiro referenciado pela variável b
	*b = 20;
	printf("%d\n",a);

	Objeto obj1;
        strcpy(obj1.nome,"info");
	obj1.dist = 100;

	Objeto *obj2;
        obj2 = &obj1;
        printf("%s %d",(*obj2).nome, (*obj2).dist);
*/

	Objeto* objetos = malloc(sizeof(Objeto)*qt); // estrutura de dados referenciada pela variável objetos para agregar toda a informação dos objetos
	int n=0; // quantidade de objetos inseridos


        // Inserção de objetos
        resultado = inserirObjeto(objetos,&n,qt,"info1",10.5); 
        resultado = inserirObjeto(objetos,&n,qt,"info2",50.5); 
        resultado = inserirObjeto(objetos,&n,qt,"info3",20.5); 
        resultado = inserirObjeto(objetos,&n,qt,"info4",10.8); 
       
        // Listagem na consola dos objetos existentes

	free(objetos);
	return 0;
}
