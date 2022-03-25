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

#pragma region PP
/**
 * @brief Create a Process Plan object
 *
 * @param npp
 * @return * Process*
 */
Process *CreateProcessPlan(int npp)
{
    printf("MAlloc process plan--\n"); // Debug
    Process *aux = (Process *)calloc(1, sizeof(Process));
    // if (aux != NULL)
    //{
    aux->npp = npp;
    aux->next = NULL;
    printf("create pp %d %p", aux->npp, aux->next);
    // }
    return aux;
}

/**
 * @brief Junta o objeto á lista process
 *
 */
Process *InsertProcessPlan(Process *prs, Process *process)
{
    if (prs != NULL)
    {
        prs->op = NULL;
        prs->next = process;
        return (prs);
    }
    else
        return (prs);
}

#pragma endregion

// Mostra todas as litas
void Showlist(Process *prs)
{

    Process *auxprs = prs;
    Operation *op = NULL;
    Machine *mch = NULL;
    printf("\nentrou showlist\n");
    while (auxprs != NULL)
    {
        printf("\nNumber npp: %p %d %p\n", auxprs, auxprs->npp, auxprs->next);
        op = auxprs->op;
        while (op != NULL)
        {
            printf(" \nOperation: %p %d %p\n", op, op->noperation, op->next);
            op = op->next;
            mch = op->machine;
            while (mch != NULL)
            {
                printf(" Machine: %d Time: %d\n", mch->pc, mch->time);
                mch = mch->next;
            }
        }

        auxprs = auxprs->next;
    }
}

#pragma region OP

Operation *CreateOperation(int nop)
{

    printf("MAlloc operações inicio"); // Debug
    Operation *aux = (Operation *)calloc(1, sizeof(Operation));

    if (aux != NULL)
    {
        aux->noperation = nop;
        aux->next = NULL;
        aux->machine = NULL;
        printf("create op %d %p", aux->noperation, aux->next);
    }
    return aux;
    ("MAlloc operações fim");
}

Process *InsertOperationProcess(Operation *opobj, Process *prs, int nprocess)
{

    Process *auxprs = prs;
    Operation *opaux = prs->op;

    printf("InsertOperation entrou"); // debug
    while (auxprs != NULL)
    {

        if (nprocess = auxprs->npp) // encontra o numero de processo igual
        {
            // dar next em op e adicionar o valor de op ao pp
            if (opobj != NULL)
            {
                Operation *aux = opaux;
                auxprs->op = opobj;
                opobj->next = aux;
                return prs;
            }
        }
        auxprs = auxprs->next;
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
    Process *auxprs = prs;
    Operation *opaux = prs->op;

    printf("InsertOperation entrou"); // debug
    while (auxprs != NULL)
    {

        if (nprocess = auxprs->npp) // encontra o numero de processo igual
        {
            // dar next em op e adicionar o valor de op ao pp

            while (opaux != NULL)
            {
                if (nop == opaux->noperation)
                {
                    if (machine != NULL)
                    {
                        Machine *aux = opaux->machine;
                        opaux->machine = machine;
                        machine->next = aux;
                        return prs;
                    }
                }
                opaux = opaux->next;
            }
        }
        auxprs = auxprs->next;
    }
    // InsertMachine();
    printf("%p -----", auxprs);

    /*  Operation *op = NULL;
      Machine *mch = NULL;
      while (prs != NULL)
      {
          if (prs->npp = process)
          {
              prs->op = op;
              while (op != NULL)
              {
                  if (op->noperation == operacao)
                  {
                      mch = MallocMachine(mch);
                      op->machine = mch;
                      mch->pc = pc;
                      mch->time = time;
                  }

                  op = op->next;
              }
          }
          prs = prs->next;
      }*/
}
#pragma endregion
#pragma endregion