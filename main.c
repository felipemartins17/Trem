#include <stdio.h>
#include <stdlib.h>
#include "headers.h"



int main()
{
    int n, t, max, id, i, rep;
    int j = 0;
    int k = 1;

    lista *saida;
    fila *entrada;



    printf("\n");
    printf("**** SIMULADOR DO PROCESSO DE REARRANJO DE VAGOES ****\n");
    printf("\nEntre com a quantidade de vagoes: ");
    scanf("%d", &n);
    printf("\nEntre com a quantidade inicial de trilhos de espera: ");
    scanf("%d", &t);
     pilha *plh[t];



    if (n!=0)
    {
        entrada = cria_fila();
        saida = cria_lista();
        for (i=0; i<t; i++)
        {
            plh[i] = cria_pilha();
        }
        for (i=0; i<n; i++)
        {


            id = rand() % n;
            /* rep = checa_repetido(entrada, id);
            /*
            if (rep == 0)
            {*/
            insere_fila(entrada, id);
            /*}
            else
            id = rand() % n;
            */

        }

        imprime_fila(entrada);

        for (i=0; i<n; i++)
        {
            if(entrada->ini->id == 1)
            {
                insere_lista(saida, id);
            }
            else
            {
                while (entrada->ini != NULL)
                {

                    if (plh[j]->topo > entrada->ini->id || plh[j]->topo == NULL) // Se o valor do elemento no topo da pilha é maior que o valor ser inserido, insere.
                    {
                        printf("ok");
                        push(plh[j], entrada->ini->id);
                        retira_vagao(entrada);

                    }
                    else if (j <= t)
                    {
                        push(plh[j++], entrada->ini->id);
                        retira_vagao(entrada);
                    }
                    else
                        plh[t+k] = cria_pilha(); // Caso tenha encerrado a quantidade de pilhas, cria mais uma
                        k++;

                }

            }
        }
        printf("\n");
        free(saida);
        libera_pilha(plh);
        libera_fila(entrada);
    }

    else
        printf("Entrar com numero de vagoes valido");

    return 0;
}
