#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{
	int machArray[10] = {1, 3};
	int timehArray[10] = {4, 5};
	int nprocess = 1;
	int nop = 33;
	// Lista ligada vazia
	Process *process = NULL;
	// process = MallocProcessPlan(process);
	process = InsertProcessPlan(process, 1);
	process = InsertProcessPlan(process,2);

	Operation *operation = NULL;
	// operation = CriaOperation(nprocess,nop);
	//
	// process = InsertOperationProcess(operation, process);

	/*	printf("Insira PP");
		printf("Insira Operation");
		printf("Insira Maquina");
		int processo = 1;
		int maquina = 1;
		int operacao = 1;
		int pc = 111;
		int time = 222;
		Machine *machine = CriaMachine(pc, time);
		InsertMachineOperacaoProcess(process, codOperacao, machine);

	*/
	Showlist(process);
}

Machine* CriaMachine(int pc, int time) {
	Machine* aux = (Machine*)calloc(1,sizeof(Machine));
	if (aux != NULL) {
		aux->pc = pc;
		aux->time = time;
	}
	return aux;
}