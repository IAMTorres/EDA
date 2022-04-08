/**
 * @file funcoes.c
 * @author GonçaloTorres (gon.im.torres@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma region Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#pragma endregion

#pragma region Metodos
/**
 * @brief Insere os dados nas estruturas
 *
 * @param process
 * @return Process*
 */
Process *InsertData(Process *process)
{
    int nprocess = 1;
    int nop = 3;
    int time = 5;
    int pc = 32;
    Process *prs = CreateProcessPlan(nprocess);
    process = InsertProcessPlan(prs, process);
    /*
        Operation *operationobj = CreateOperation(nop);
        process = InsertOperationProcess(operationobj, process, nprocess);

        Machine *machineobj = CreateMachine(pc, time);
        process = InsertMachineOperationProcess(process, machineobj, nop, nprocess);*/

    Operation *operationobj = CreateOperation(01);
    process = InsertOperationProcess(operationobj, process, 1);
    operationobj = CreateOperation(02);
    process = InsertOperationProcess(operationobj, process, 1);
    operationobj = CreateOperation(03);
    process = InsertOperationProcess(operationobj, process, 1);
    operationobj = CreateOperation(04);
    process = InsertOperationProcess(operationobj, process, 1);

    Machine *machineobj = CreateMachine(1, 4);
    process = InsertMachineOperationProcess(process, machineobj, 1, nprocess);

    machineobj = CreateMachine(3, 5);
    process = InsertMachineOperationProcess(process, machineobj, 1, nprocess);

    machineobj = CreateMachine(2, 4);
    process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);

    machineobj = CreateMachine(4, 5);
    process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);

    machineobj = CreateMachine(2, 4);
    process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);

    machineobj = CreateMachine(4, 5);
    process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);

    machineobj = CreateMachine(3, 5);
    process = InsertMachineOperationProcess(process, machineobj, 3, nprocess);

    machineobj = CreateMachine(5, 6);
    process = InsertMachineOperationProcess(process, machineobj, 3, nprocess);

    machineobj = CreateMachine(4, 5);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);

    machineobj = CreateMachine(5, 5);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);
    machineobj = CreateMachine(6, 4);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);

    machineobj = CreateMachine(7, 5);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);
    machineobj = CreateMachine(8, 9);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);
    return process;
}
/**
 * @brief Faz a leitura do ficheiro
 *
 * @param process
 * @return Process*
 */
Process *ReadFile(Process *process)
{

    FILE *fl = fopen("dados.txt", "rt");
    char str[50];
    char str1[50];
    int machine[10];
    int time[10];
    char *pch;

    int op;
    if (fl != NULL)

        if (!feof(fl))
        {
            fscanf(fl, "%d;%[^;];%[^;]\n", &op, str, str1);
            printf("%d %s %s", op, str, str1);
            fclose(fl);
        }
    pch = strtok(str, ",");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, ",");
    }

    return process;
}
/**
 * @brief Retorna o endereço de memoria do ProcessPlan
 *
 * @param prs
 * @param nProcess
 * @return Process*
 */
Process *SearchProcessPlan(Process *prs, int nProcess)
{

    Process *auxPrs = prs;

    while (auxPrs != NULL)
    {
        if (nProcess == auxPrs->npp)
        {
            return auxPrs;
        }

        auxPrs = auxPrs->next;
    }
}
/**
 * @brief Retorna o endereço de memoria de Operation
 *
 * @param op
 * @param nOperation
 * @return Operation*
 */
Operation *SearchOperation(Operation *op, int nOperation)
{
    Operation *auxOp = op;
    while (auxOp != NULL)
    {
        if (nOperation == auxOp->noperation)
        {
            return auxOp;
        }
        auxOp = auxOp->next;
    }
}
/**
 * @brief Retorna o endereço de memoria de Machine
 *
 * @param mch
 * @param nMachine
 * @return Machine*
 */
Machine *SearchMachine(Machine *mch, int nMachine)
{
    Machine *auxMch = mch;
    while (auxMch != NULL)
    {
        if (nMachine == auxMch->pc)
        {
            return auxMch;
        }
        auxMch = auxMch->next;
    }
}
/**
 * @brief Altera os valores de maquina
 *
 * @param process
 * @param nProcess
 * @param nOperation
 * @param nMachine
 * @return Machine*
 */
Machine *ChangeMachine(Process *process, int nProcess, int nOperation, int nMachine)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, nProcess);
        op = prs->op;
        op = SearchOperation(op, nOperation);
        if (op != NULL)
        {
            mch = op->machine;
        }
        if (mch != NULL)
        {
            mch = SearchMachine(mch, nMachine);
        }
    }
    return mch;
}

#pragma region PP

/**
 * @brief Create a Process Plan object
 *
 * @param npp
 * @return * Process*
 */
Process *CreateProcessPlan(int npp)
{

    Process *aux = (Process *)calloc(1, sizeof(Process));
    if (aux != NULL)
    {
        aux->npp = npp;
        aux->next = NULL;
    }
    return aux;
}

/**
 * @brief Junta o objeto á lista process
 *
 */
Process *InsertProcessPlan(Process *prsobj, Process *process)
{
    if (prsobj != NULL)
    {
        prsobj->op = NULL;
        prsobj->next = process;
        return (prsobj);
    }
    else
        return (process);
}

#pragma endregion

/**
 * @brief  Mostra todas as litas
 *
 * @param prs
 */
void Showlist(Process *prs)
{
    Process *auxPrs = prs;
    Operation *op = NULL;
    Machine *mch = NULL;
    while (auxPrs != NULL)
    {
        printf("\nNumber npp: %p %d %p\n", auxPrs, auxPrs->npp, auxPrs->next);
        op = auxPrs->op;
        while (op != NULL)
        {
            printf(" \n    Operation: %p %d %p\n", op, op->noperation, op->next);

            mch = op->machine;
            while (mch != NULL)
            {
                printf("       Machine: %d Time: %d\n", mch->pc, mch->time);
                mch = mch->next;
            }

            op = op->next;
        }

        auxPrs = auxPrs->next;
    }
}
/**
 * @brief Mostra todos os valores
 *
 * @param process
 * @param prsSub
 * @param opSub
 * @return int
 */
int ShowOperation(Process *process, int prsSub, int opSub)
{

    Process *auxPrs = process;
    Operation *op = NULL;
    Machine *mch = NULL;
    while (auxPrs != NULL)
    {
        if (prsSub == auxPrs->npp)
        {
            op = auxPrs->op;
            while (op != NULL)
            {
                if (opSub == op->noperation)
                {
                    mch = op->machine;
                    while (mch != NULL)
                    {
                        printf("\n       Machine: %d Time: %d\n", mch->pc, mch->time);
                        mch = mch->next;
                    }
                    return 1;
                }

                op = op->next;
            }
        }

        auxPrs = auxPrs->next;
    }
}

#pragma region OP
/**
 * @brief Cria o obejeto operation
 *
 * @param nOp
 * @return Operation*
 */
Operation *CreateOperation(int nOp)
{

    Operation *aux = (Operation *)calloc(1, sizeof(Operation));

    if (aux != NULL)
    {
        aux->noperation = nOp;
        aux->next = NULL;
        aux->machine = NULL;
    }
    return aux;
}
/**
 * @brief Insere o objeto no processo
 *
 * @param opobj
 * @param prs
 * @param nprocess
 * @return Process*
 */
Process *InsertOperationProcess(Operation *opobj, Process *prs, int nprocess)
{

    Process *auxPrs = prs;
    Operation *opaux = prs->op;
    while (auxPrs != NULL)
    {

        if (nprocess = auxPrs->npp) // encontra o numero de processo igual
        {
            // dar next em op e adicionar o valor de op ao pp
            if (opobj != NULL)
            {
                Operation *aux = opaux;
                auxPrs->op = opobj;
                opobj->next = aux;
                return prs;
            }
        }
        auxPrs = auxPrs->next;
    }
}

void RemoveOperation(Process *prs, int prsSubs, int opSubs)
{

    Process *auxPrs = prs;
    Operation *op = NULL;
    Machine *mch = NULL;
    while (auxPrs != NULL)
    {
        if (prsSubs == auxPrs->npp)
        {printf("ja deu");
            op = auxPrs->op;
            Operation *nodoAtual = op, *nodoAnterior;
            if (op->noperation == opSubs)
            {
                printf("entrou if");
                op = nodoAtual->next;
                free(nodoAtual);
                free(op->machine);
            }
            else
            {
                nodoAnterior = op;
                nodoAtual = nodoAnterior->next;
                while ((nodoAtual != NULL) && (nodoAtual->noperation != opSubs))
                {
                    nodoAnterior = nodoAtual;
                    nodoAtual = nodoAtual->next;
                }
                if (nodoAtual != NULL)
                {
                    nodoAnterior->next = nodoAtual->next;
                    free(nodoAtual);
                    Machine *mchRemove = nodoAtual->machine;
                    Machine *auxRemoveMachine;
                    while (mchRemove != NULL)
                    {
                        auxRemoveMachine = mchRemove;
                        mchRemove = mchRemove->next;
                        free(auxRemoveMachine);
                    }
                }
                // return (lista);
            }
            break;
        }
        auxPrs = auxPrs->next;
    }
}

#pragma endregion
#pragma region MCH

Machine *CreateMachine(int pc, int time)
{
    printf("MAlloc machine--\n"); // Debug
    Machine *aux = (Machine *)calloc(1, sizeof(Machine));

    aux->pc = pc;
    aux->time = time;
    aux->next = NULL;
    printf("create machine %d %d %p", aux->pc, aux->time, aux->next);
    return aux;
}

Process *InsertMachineOperationProcess(Process *prs, Machine *machine, int nop, int nprocess)
{
    Process *auxPrs = prs;
    Operation *opaux = prs->op;

    printf("InsertOperation entrou"); // debug
    while (auxPrs != NULL)
    {

        if (nprocess == auxPrs->npp) // encontra o numero de processo igual
        {
            // dar next em op e adicionar o valor de op ao pp

            while (opaux != NULL)
            {
                if (nop == opaux->noperation)
                {
                    if (machine != NULL)
                    {
                        machine->next = opaux->machine;

                        Machine *aux = opaux->machine;
                        opaux->machine = machine;
                        machine->next = aux;
                        return prs;
                    }
                }
                opaux = opaux->next;
            }
        }
        auxPrs = auxPrs->next;
    }
    // InsertMachine();
    printf("%p -----", auxPrs);
}
#pragma endregion

float MeanLow(Process *process, int processMeanLow)
{

    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    int sum = 0;
    float mean = 0;
    int count = 0;
    int lowTime;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, processMeanLow);
        op = prs->op;
        printf("\noper %p", prs->op);

        while (op != NULL)
        {

            op = SearchOperation(op, op->noperation);
            mch = op->machine;
            lowTime = mch->time;
            printf("\nxxxxxxx %d\n", lowTime);
            while (mch != NULL)
            {

                printf("\n----tempo %d e %d\n", lowTime, mch->time);
                mch = SearchMachine(mch, mch->pc);

                if (mch->time < lowTime)
                {
                    printf("foi desta");
                    lowTime = mch->time;
                }
                mch = mch->next;
            }
            sum = sum + lowTime;
            count++;
            op = op->next;
        }
    }

    mean = sum / count;
    printf("\noiii------%d", count);
    return mean;
}

float MeanHigh(Process *process, int processMeanHigh)
{

    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    int sum = 0;
    float mean = 0;
    int count = 0;
    int highTime;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, processMeanHigh);
        op = prs->op;

        while (op != NULL)
        {

            op = SearchOperation(op, op->noperation);
            mch = op->machine;

            highTime = 0;
            while (mch != NULL)
            {
                mch = SearchMachine(mch, mch->pc);

                // count++;
                if (mch->time > highTime)
                {

                    highTime = mch->time;
                }
                mch = mch->next;
            }
            sum = sum + highTime;
            count++;
            op = op->next;
        }
    }

    mean = sum / count;

    return mean;
}

#pragma endregion