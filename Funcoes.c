#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define TamMax 3


fila *cria_fila ()
{
    fila *novo = (fila *) malloc (sizeof (fila));
    novo->ini = novo->fim = NULL;
    return novo;
}

pilha *cria_pilha ()
{
    pilha *novo = (pilha *) malloc (sizeof (pilha));
    novo->topo = NULL;
    return novo;
}

vagao *cria_vagao (int id)
{
    vagao *novo = (vagao *) malloc (sizeof (vagao));
    novo->prox = NULL;
    novo->id = id;
    return novo;
}

lista *cria_lista (void)
{
    return NULL;
}

lista *insere_lista (lista * l, int id)
{
    lista *novo = (lista *) malloc (sizeof (lista));
    novo->info = id;
    novo->prox = l;
    return novo;
}

void insere_fila (fila * f, int id)
{
    vagao *novo = cria_vagao (id);
    if (f->fim == NULL)
    {
        f->ini = f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void libera_fila (fila * f)
{
    vagao *aux;
    while (f->ini != NULL)
    {
        aux = f->ini;
        f->ini = f->ini->prox;
        free (aux);
    }
    free (f);
}

void push (pilha * p, int id)
{
    vagao *novo = cria_vagao (id);
    if (p->topo == NULL)
    {
        p->topo = novo;
    }
    else
    {
        novo->prox = p->topo;
        p->topo = novo;
    }
}

void pop (pilha * p)
{
    vagao *aux;
    if (p->topo == NULL)
    {
        return;
    }
    else
    {
        aux = p->topo;
        p->topo = p->topo->prox;
        free (aux);
        return;
    }
}

void libera_pilha (pilha * p)
{
    vagao *aux;
    if (p == NULL)
        return;
    while (p->topo != NULL)
    {
        aux = p->topo;
        p->topo = p->topo->prox;
        free (aux);
    }
    free (p);
}

void retira_vagao (fila * f)
{
    vagao *aux;
    aux = f->ini;
    f->ini = f->ini->prox;
    free (aux);
}

void imprime_fila (fila * f)
{
    while (f->ini->prox != NULL)
    {
        printf ("%d\t", f->ini->id);
        f->ini = f->ini->prox;
    }
}

int checa_repetido (fila * f, int id)
{
    while (id != NULL)
    {
        if (f->ini->id == id)
        {
            return 1;
            break;
        }
        else
            f->ini = f->ini->prox;
    }
    return 0;
}

void pilha_cheia(pilha* plh)
{
    if (plh->topo == TamMax)
    {
        printf("Pilha cheia\n");
    }
}




