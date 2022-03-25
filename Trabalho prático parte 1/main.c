/**
 * @file main.c
 * @author GonçaloTorres (gon.im.torres@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022
 * Professor:
 */
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
	int nop1 = 53;
	// Lista ligada vazia
	Process *process;
	Process *prs = CreateProcessPlan(nprocess);
	process = InsertProcessPlan(prs, process);

	Operation *operationobj = CreateOperation(nop);
	process = InsertOperationProcess(operationobj, process, nprocess);

	operationobj = CreateOperation(3);
	process = InsertOperationProcess(operationobj, process, nprocess);

	printf("Insira PP");
	printf("Insira Operation");
	printf("Insira Maquina");
	int processo = 1;
	int maquina = 1;
	int operacao = 1;
	int pc = 111;
	int time = 222;
	Machine *machine = CreateMachine(pc, time);
	process = InsertMachineOperationProcess(process, machine, nop, nprocess);
	Showlist(process);

}