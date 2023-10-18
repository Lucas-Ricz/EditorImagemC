#include "libTrabalho.h"

int **leArquivoImagem(char *nomeArqEntrada, char *tipo, int *lin, int *col, int *maxval)
{
    //Abrindo arquivo texto no modo leitura
    FILE *arq = fopen(nomeArqEntrada, "r");
    *lin = 0;
    *col = 0;
    *maxval = 0;
    //Verifica se arquivo abriu corretamente, se caso contrário retorna NULL
    if (arq == NULL)
    {
        printf("Falha ao abrir o arquivo!\n"
               "Função leArquivoImagem\n");
        return NULL;
    }
    //Lendo informações sobre arquivo, e as guarda nos respectivos parametros
    fscanf(arq, "%s %d %d %d ", tipo, col, lin, maxval);
    //Declara e aloca matriz de forma dinâmica
    int **mat = alocaMatrizImagem(*lin, *col);
    int i, j;
    //Lendo informações sobre a matriz
    for (i = 0; i < *lin; i++)
    {
        for (j = 0; j < *col; j++)
        {
            fscanf(arq, "%d ", &mat[i][j]);
        }
    }
    //Fecha arquivo e retorna a matriz
    fclose(arq);
    return mat;
}
