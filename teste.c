//-------------------------------------------------------------------------------------------------------
/*
*@3
*Desenvolva a função a qual recebe três parâmetros:
* ‘valor_ref’: Valor de referencia
* ‘array’: array de inteiros
* ‘tamanho_array’: quantidade de elementos no array
*Esta função deve devolver a maior quantidade de elementos do array que somados resulta em um valor menor ou igual ao
*parâmetro 'valor_ref'
*
*Ex.: arr [4,2,3,1,5,6]
* valor_ref = 7
* retorno = 3; (representado pelos elementos do array [2,3,1] => 2+3+1 = 6 que é menor que 'valor_ref')
*/
//-------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//função auxiliar para preencher nosso array de inteiros.
//arry_int sera preenchido com os valores inseridos
//max_elementos quantidade maxima de elementos que o array_int pode receber
//retorna a quantidade de elementos inteiros maiores que zero foram inseridos
int criar_array(int *array_int, int max_elementos){
    int idx = 0;
    char array_str[128];
    char valor[16];
    char *posicao_inicio = NULL;
    char *posicao_fim = NULL;

    printf ("Informe os valores do tipo inteiros, separados por virgula\n");
    scanf ("%s", array_str);
    if (strlen (array_str) > 0)
    {
        posicao_inicio = array_str;
        do {
            posicao_fim = strchr (posicao_inicio, ',');
            memset(valor,0, sizeof(valor));
            if (posicao_fim != NULL)
            {
                memcpy(valor, posicao_inicio,(int) (posicao_fim - posicao_inicio) );
                posicao_inicio = (posicao_fim + 1 );
            }
            else if(posicao_inicio != NULL)

            if(strlen(valor))
                array_int[idx++] = atoi(valor);

        } while (posicao_fim != NULL && idx < max_elementos);
    }

    printf ("ARRAY -> [" );
    for(int i=0; i<idx; ++i)
    {
        printf ("%d", array_int[i]);
        if(i+1 < idx){
        printf(",");
        }
    }
    printf ("] \n");
    return idx;
}


void    bubble_sort(int* array, int tamanho_array)
{
    int aux = 0;
    for (int i = 1; i < tamanho_array; i++) 
    {
        for (int j = 0; j < tamanho_array - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}


int maximo_elementos(int valor_ref, int* array, int tamanho_array) {

    //1 Task: organizar o arry de forma crescente.

    printf("tamanho array: %d", tamanho_array);
    printf("Antes do bubble sort:\n");
    for(int i = 0; i < tamanho_array; i++)
        printf("%d\n", array[i]);

    bubble_sort(array, tamanho_array);

    printf("Depois do bubble sort:\n");
    for(int i = 0; i < tamanho_array; i++)
        printf("%d\n", array[i]);


}

int main () {
    const int max_elementos = 128;
    int array_int[max_elementos] ;
    int qtd_elementos = 0;
    int tamanho_array = 0;
    int valor_ref = 0;
    tamanho_array = criar_array(array_int, max_elementos);
    printf("Informe o valor para agrupamento.\n");
    scanf ("%d", &valor_ref);
    qtd_elementos = maximo_elementos(valor_ref, array_int, tamanho_array);

    printf("O numero maximo de agrupamente e [%d].\n", qtd_elementos);

    return 0;
}


