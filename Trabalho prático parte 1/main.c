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
#include <time.h>

int main()
{ /*

	 int nprocess = 1;
	 int nprocess2 = 2;
	 int nop = 33;
	 int nop1 = 53;
	 int nop2 = 33;
	 int nop12 = 53;
	 // Lista ligada vazia
	 Process *process;
	 Process *prsObj = CreateProcessPlan(nprocess);
	 process = InsertProcessPlan(prsObj, process);

	 Operation *operationobj = CreateOperation(nop);
	 process = InsertOperationProcess(operationobj, process, nprocess);
	 operationobj = CreateOperation(3);
	 process = InsertOperationProcess(operationobj, process, nprocess);
	 int pc = 111;
	 int time = 222;
	 Machine *machineobj = CreateMachine(pc, time);
	 process = InsertMachineOperationProcess(process, machineobj, nop, nprocess);
	 Machine *machine = CreateMachine(12, 21);
	 process = InsertMachineOperationProcess(process, machine, 3, nprocess);
 */
	int opSub;
	int prsSub;
	int mchSub;
	int timeSub;
	//	Showlist(process);
	int option = 0;
	Process *process = NULL;
	do
	{

		printf("\nInsira a opcao:\nOption:");
		scanf("%d", &option);
		switch (option)
		{
		case 1:

			/*process = ReadFile(process);*/
			// Lista ligada vazia
			process = InsertData(process);
			Showlist(process);
			break;
		case 2:
			printf("\nInsira o processo a remover\nProcesso:");
			scanf("%d", &prsSub);

			printf("\nInsira a operação a remover\nOperação:");
			scanf("%d", &opSub);

			RemoveOperation(process, prsSub, opSub);
			printf("\n-----------------------------------------------------------------------------\n");

			break;
		case 3: // Alterar
			int rtr = 0;

			printf("\nInsira o processo a alterar\nProcesso:");
			scanf("%d", &prsSub);

			printf("\nInsira a operação a alterar\nOperação:");
			scanf("%d", &opSub);

			rtr = ShowOperation(process, prsSub, opSub);

			if (rtr == 0)
				printf("\nOpções inválida");

			printf("\nInsira a maquina a alterar\nOperação:");
			scanf("%d", &mchSub);
			printf("\n---conteudo %d %p ", process->npp, process->next);
			printf("-----------------");
			Machine *objMchSubs = NULL;
			objMchSubs = ChangeMachine(process, prsSub, opSub, mchSub);

			printf("Novo numero de maquina:\nMaquina:");
			scanf("%d", &mchSub);
			printf("Novo tempo da maquina %d:\nMaquina:", mchSub);
			scanf("%d", &timeSub);
			objMchSubs->pc = mchSub;
			objMchSubs->time = timeSub;

			
			break;
		case 4: // Media mais baixa
			int processMeanLow;
			printf("Insira o processo a calcular: ");
			scanf("%d", &processMeanLow);
			printf("\n A media mais baixa é: %.2f", MeanLow(process, processMeanLow));
			break;

		case 5: // Media mais baixa
			int processMeanHigh;
			printf("Insira o processo a calcular: ");
			scanf("%d", &processMeanHigh);
			printf("\n A media mais baixa é: %.2f", MeanHigh(process, processMeanHigh));
			break;
		case 69:
			Showlist(process);
			break;
		default:
			break;
		}

	} while (option != 0);
}
