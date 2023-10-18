#include "libTrabalho.h"

int **alocaMatrizImagem(int lin, int col)
{
   //Definindo variaveis e alocando matriz de forma dinâmica
   int i;
   int **mat = (int **)malloc(lin * sizeof(int *));

   //Verificação de memória suficiente
   if (mat == NULL)
   {
      printf("Memória insuficiente!\n"
             "Função alocaMatrizImagem\n");
      return NULL;
   }

   //Alocação dinâmica da matriz
   for (i = 0; i < lin; i++)
   {
      mat[i] = (int *)malloc(col * sizeof(int));
      //Verificação de memória suficiente e desaloca linha da matriz anterior
      if (mat[i] == NULL)
      {
         desalocaMatrizImagem(mat, i);
         printf("Memória insuficiente!\n"
                "Função alocaMatrizImagem\n");
         return NULL;
      }
   }
   //Retorna matriz alocada
   return mat;
}
