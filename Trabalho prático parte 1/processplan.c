#pragma region Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#pragma endregion

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

void RemoveOperation(Process *process, int opPrs, int opSubs)
{


}

#pragma endregion