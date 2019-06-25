#include <stdio.h>
#include <stdlib.h>

typedef struct Vagao vagao;
typedef struct Pilha pilha;
typedef struct Fila fila;
typedef struct Lista lista;

struct Vagao
{
    int id;
    vagao *prox;
};


struct Pilha
{
    vagao *topo;
};


struct Fila
{
    vagao *ini, *fim;
};

struct Lista
{
    int info;
    struct lista *prox;
};

lista *cria_lista();
fila *cria_fila();
pilha *cria_pilha();
vagao *cria_vagao(int id);
int checa_repetido (fila *f, int id);
void insere_fila(fila *f, int id);
void libera_fila(fila *f);
void push(pilha *p, int id);
void pop(pilha *p);
void libera_pilha(pilha *p);
void retira_vagao(fila *f);
void imprime_fila(fila *f);
