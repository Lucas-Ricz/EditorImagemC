#include "libTrabalho.h"

char *alocaString(int size)
{
    //Declarando variáveis e alocando uma string de forma dinâmica de acordo com o size passado
    char *v = NULL;
    v = (char *)malloc(size * sizeof(char));
    //Verificação de memória suficiente
    if (v == NULL)
    {
        printf("\nMemória insuficiente -"
               " função alocaString\n");
    }
    //Retorna a string alocada
    return v;
}
