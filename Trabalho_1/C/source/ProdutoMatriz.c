#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ProdutoMatriz.h" //precisa editar makefile para incluir essa biblioteca


void Multiplica_matriz_vetor(int tamanho)
{

    double **matrizA, *vetorB, *vetorX, soma, numeroAleatorio;
    int linha, coluna;
    clock_t inicio, inicio2, fim, fim2;
    double difTempo, difTempo2;

    matrizA = (double **)malloc (tamanho * sizeof (double*)) ;
    vetorB = (double *)malloc (tamanho * sizeof (double)) ;
    vetorX = (double *)malloc (tamanho * sizeof (double)) ;

    //alocando espaço em cada coluna de cada linha da MatrizA
    for (coluna=0; coluna < tamanho; coluna++)
        matrizA[coluna] = (double *)malloc (tamanho * sizeof (double));

    srand(time(NULL));

    //preencher array
    for (linha=0; linha< tamanho; linha++)
        for (coluna=0; coluna < tamanho; coluna++){
            //numeroAleatorio = (double)(rand() % tamanho);
            numeroAleatorio = (100000000000 / (double) RAND_MAX) * (double) rand();
            matrizA[linha][coluna] = numeroAleatorio;
        }

    //preencher vetor
    for (coluna=0; coluna < tamanho; coluna++)
        vetorX[coluna] = (double)(rand()*tamanho);
    
    ///calculando tempo para multiplicar matriz
    inicio = clock();

    for (linha=0; linha<tamanho; linha++){
        soma=0;
        for (coluna=0; coluna<tamanho; coluna++){
            soma += matrizA[linha][coluna]*vetorX[coluna];
        }
        vetorB[linha] = soma;
    }

    fim =clock();

    free (vetorB) ;
    vetorB = (double *)malloc (tamanho * sizeof (double)) ;


    inicio2=clock();
    for (coluna=0; coluna<tamanho; coluna++){
        soma=0;
        for (linha=0; linha<tamanho; linha++){
            soma += matrizA[linha][coluna]*vetorX[coluna];
        }
        vetorB[coluna] = soma;
    }

    fim2 =clock();

    difTempo = ((double)(fim - inicio))/CLOCKS_PER_SEC;
    difTempo2 = ((double)(fim2 - inicio2))/CLOCKS_PER_SEC;


/*     //prints

    printf("Matriz A \n");

    for (linha = 0; linha < tamanho; linha++){
        for(coluna = 0; coluna < tamanho; coluna++){
            printf ("%d ", matrizA[linha][coluna]);
        }
        printf ("\n");
    }

    printf("Vetor x \n");

    for (linha = 0; linha < tamanho; linha++){
        printf ("%d \n",vetorX[linha]);
    }

    printf("Matriz B \n");

    for (linha = 0; linha < tamanho; linha++){
        printf ("%d\n", vetorB[linha]);
    }
 */    


    printf("%d: %.5f - %.5f seconds.\n", tamanho, difTempo, difTempo2);

    //liberando memória
    for (linha=0; linha < tamanho; linha++)
        free (matrizA[linha]) ;
    free (matrizA) ;
    free (vetorX) ;
    free (vetorB) ;
}

int main (int argc, char * argv[])
{
    //int tamanho_matriz =  atoi(argv[1]);

    for(int tamanho_matriz=1; tamanho_matriz<60000; tamanho_matriz+=500){
        Multiplica_matriz_vetor(tamanho_matriz);
    }
    return 0;
}


