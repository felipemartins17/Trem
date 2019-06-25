#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define TamMax 3


int
main ()
{

    int n, num_trilhos, max, id, i, rep, aux;

    int j = 0;

    int k = 1;

    pilha **plh;

    lista *saida;

    fila *entrada;

    printf ("\n");

    printf ("**** SIMULADOR DO PROCESSO DE REARRANJO DE VAGOES ****\n");

    printf ("\nEntre com a quantidade de vagoes: ");

    scanf ("%d", &n);

    printf ("\nEntre com a quantidade inicial de trilhos de espera: ");

    scanf ("%d", &num_trilhos);


    if (n != 0)

    {

        entrada = cria_fila ();

        saida = cria_lista ();

        plh = (pilha**)malloc(num_trilhos*sizeof(pilha*));


        for (i = 0; i < num_trilhos; i++)

        {

            plh[i] = cria_pilha ();

        }

        for (i = 0; i < n; i++)

        {

            id = rand () % n;

            /* rep = checa_repetido(entrada, id);
            /*
            if (rep == 0)
            {*/
            insere_fila (entrada, id);

            /*}
            else
            id = rand() % n;
            */
        }

        imprime_fila (entrada);


        while (entrada->ini != NULL)

        {
/*
            if (entrada->ini->id == 1)

            {

                insere_lista (saida, id);
                retira_vagao (entrada);
                continue;


            }
*/

            for (j = 0; j < num_trilhos; j++)

            {

                if (plh[j]->topo->id > entrada->ini->id && !pilha_cheia (plh[j]))	// Se o valor do elemento no topo da pilha e maior que o valor ser inserido, insere.
                {

                    printf ("ok");
                    push (plh[j], entrada->ini->id);
                    retira_vagao (entrada);
                    break;

                }

                else if (plh[j]->topo->id == NULL)

                {

                    push (plh[j], entrada->ini->id);
                    retira_vagao (entrada);
                    break;

                }

                else

                plh[num_trilhos + k] = cria_pilha ();	// Caso tenha encerrado a quantidade de pilhas, cria mais uma
                num_trilhos++;

                push (plh[j + k], entrada->ini->id);
                retira_vagao (entrada);
                break;

            }

        }


        printf ("\n");

        free (saida);

        libera_pilha (plh);

        libera_fila (entrada);

    }

    else

        printf ("Entrar com numero de vagoes valido");

    return 0;

}
