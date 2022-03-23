#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Process *MallocProcessPlan(Process *prs)
{
    printf("MAlloc process plan\n"); // Debug
    prs = (Process *)malloc(sizeof(Process));
    return (prs);
}

Process *InsertProcessPlan(Process *prs, int nnp)
{
    Process *prsobj = MallocProcessPlan(prs);
    if (prsobj != NULL)
    {
        prsobj->npp = nnp;
        prsobj->op = NULL;
        prsobj->next = prs;
        return (prsobj);
    }
    else
        return (prs);
}

void Showlist(Process *prs)
{
    Operation *op = NULL;
    Machine *mch = NULL;
    printf("\nentrou showlist\n");
    while (prs != NULL)
    {
        printf("Number npp: %d\n", prs->npp);
        op = prs->op;
        while (op != NULL)
        {
            printf(" Operation: %d\n", op->noperation);
            mch = op->machine;
            while (mch != NULL)
            {
                printf(" Machine: %d Time: %d\n", mch->pc, mch->time);
            }
            prs = prs->next;
        }

        prs = prs->next;
    }
}

Operation *MallocOperation(Operation *op)
{
    printf("MAlloc operações inicio"); // Debug
    op = (Operation *)malloc(sizeof(Operation));
    return (op);
    printf("MAlloc operações fim");
}

Operation *InsertOperation(Operation *op, Process *prs, int nprocess, int nop)
{ printf("\n %p %d  ",op, prs->npp);
    printf("\ninserto before malloc\n");
   // Operation *opobj = MallocOperation(op);
  
    Operation *opobj = (Operation *)malloc(sizeof(Operation));
    printf("InsertOperation entrou"); // debug
    while (prs != NULL)
    {
        if (nprocess = prs->npp)
        {
            while (op != NULL)

                if (opobj != NULL)
                {
                    opobj->machine = NULL;
                    opobj->noperation = nop;
                    opobj->next = op;
                }
                else
                    return (op);
        }
    }

    // InsertMachine();

    return op;
}
Machine *MallocMachine(Machine *mch)
{
    printf("MAlloc machine"); // Debug
    mch = (Machine *)malloc(sizeof(Machine));
    return (mch);
}
void InsertMachine(Process *prs, int process, int maquina, int operacao, int pc, int time)
{
    Operation *op = NULL;
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
    }
}
