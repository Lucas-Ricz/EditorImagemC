#include "libTrabalho.h"

void desalocaMatrizImagem(int **mat, int lin)
{
   //Declarando variáveis
   int i;
   //Desaloca matriz 
   for (i = 0; i < lin; i++)
   {
      free(mat[i]);
   }
   free(mat);
}
